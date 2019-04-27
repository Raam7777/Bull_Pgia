#pragma once
#include <iostream>
#include <string>
#include "Guesser.hpp"
using std::string;
using namespace std;

namespace bullpgia {

  class SmartGuesser : public bullpgia::Guesser {

  public:

    string guess();
    void startNewGame(uint length);
    void learn(string str);
  };
}
