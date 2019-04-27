#pragma once
#include <iostream>
#include <string>
#include "calculate.hpp"
using std::string;

namespace bullpgia {

  class Guesser {

  public:

    unsigned int length;

    virtual string guess() = 0;
    virtual void startNewGame(uint length) {};
    virtual void learn(string str){};
  };
}
