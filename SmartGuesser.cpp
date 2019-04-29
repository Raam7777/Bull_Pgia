#include <iostream>
#include <string>
#include "SmartGuesser.hpp"
using std::string;
using namespace bullpgia;


string SmartGuesser::guess()
{
  for(int i=0; i<ans.length(); i++){
    for(int i=0; i<ans.length(); i++){

    }
  }
  return "";
}

void SmartGuesser::startNewGame(uint length)
{
  if(ans.length() != length){
    throw "diffrent length";
  }
}

void SmartGuesser::learn(string str)
{

}
