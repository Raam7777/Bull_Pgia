#pragma once
#include <iostream>
#include <string>
#include "Guesser.hpp"
#include "Chooser.hpp"
using std::string;
using namespace std;

namespace bullpgia {

  class SmartGuesser : public bullpgia::Guesser {
  string str = "0000";
  int countB, countP;
  char value[10] = {'0','1','2','3','4','5','6','7','8','9'};

  public:

    string guess();
    void startNewGame(uint length);
    void learn(string str);
  };
}
