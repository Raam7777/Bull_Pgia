#include <iostream>
#include <string>
#include "calculate.hpp"
using std::string;
using namespace bullpgia;

string bullpgia::calculateBullAndPgia(string choice, string guess){
    int count_bull = 0, count_pgia = 0;
    for(int i=0; i<choice.length(); i++)
    {
      for(int j=0; j<guess.length(); j++)
      {
        if(choice[i]==guess[j])
        {
          count_pgia++;
          if(i==j)
          {
            count_bull++;
            count_pgia--;
          }
        }
      }
    }

  string ans = std::to_string(count_bull) + "," + std::to_string(count_pgia);
  return ans;
}
