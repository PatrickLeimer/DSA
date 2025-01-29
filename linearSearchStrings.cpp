#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool containsTarget(vector<string> container, string target) 
{
  for(int i = 0; i < container.size(); i++) {
    if(container[i] == target) {
      return true;
    }
  }
    return false;
  }