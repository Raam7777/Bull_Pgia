/**
 * A demo program for bull-pgia.
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}


		// -----------------------my test-------------------------------\\

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1230","1234"), "3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1230","4321"), "0,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1200","1234"), "2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1200","4321"), "0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1000","1234"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1000","4321"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("1243","1234"), "2,2")
		.CHECK_OUTPUT(calculateBullAndPgia("4132","4321"), "1,3")
		.CHECK_OUTPUT(calculateBullAndPgia("1243","0000"), "0,0")

		.CHECK_OUTPUT(calculateBullAndPgia("0","0"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1","0"), "0,0")

		.CHECK_OUTPUT(calculateBullAndPgia("00","01"), "1,3")
		.CHECK_OUTPUT(calculateBullAndPgia("12","21"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("44","00"), "1,3")

		.CHECK_OUTPUT(calculateBullAndPgia("124","001"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("413","432"), "1,1")
		.CHECK_OUTPUT(calculateBullAndPgia("123","123"), "3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("321","231"), "1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("124","000"), "0,0")

		.CHECK_OUTPUT(calculateBullAndPgia("123456789","123456789"), "9,0")
		.CHECK_OUTPUT(calculateBullAndPgia("123498765","123456789"), "5,4")
		;

		ConstantChooser c0000{"0000"}, c123456{"123456"}, c6060{"6060"};
		ConstantGuesser g123456{"123456"}, g123{"123"}, g0606{"0606"};

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c123456, g123456, 6, 100), 1)    // guesser wins in one turn.
		.CHECK_EQUAL(play(c123456, g123, 6, 100), 101)    // guesser loses technically by making an illegal guess (too short).
		.CHECK_EQUAL(play(c0000, g123456, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c0000, g123456, 6, 100), 0)     // chooser loses technically by choosing an illegal number (too short).
		.CHECK_EQUAL(play(c6060, g123, 3, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c6060, g0606, 4, 100), 101)    // guesser loses by running out of turns
		;

		testcase.setname("Play with smart guesser");
		SmartGuesser smarty2;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(c0000, smarty2, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(c6060, smarty2, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(c123456, smarty2, 5, 100)>10, true);  // smarty should always win in at most 10 turns!
		}


    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
