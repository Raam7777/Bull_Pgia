#pragma once
#include <iostream>
#include <string>
using std::string;

namespace bullpgia {

  class Chooser{

  public:
    virtual string choose(uint lenght) = 0;
  };
}
