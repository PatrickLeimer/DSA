// Patrick Leimer -- Partner is -> Ilani Seguinot
#include <iostream>
#include <string>
using namespace std; 

int suffixCount(std::string S, int L) {
  // Your code here
  // S = "helloing buting yelling butloing ingtobeeing";
  // L = 3;
  int tempCount = 0;
  int lenS = S.length();
  string temp = S.substr(lenS - L, lenS);
  for(int i = 0; i < lenS; i++ ) {
        string temp2 = S.substr(i, L);
    if ( temp2 == temp) {
      tempCount++;
    } 
  }

  return tempCount;
}