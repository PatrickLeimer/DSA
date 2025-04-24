#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


// 1st Problem
bool containsTarget(vector<string> container, string target) 
{
  for(int i = 0; i < container.size(); i++) {
    if(container[i] == target) {
      return true;
    }
  }
    return false;
  }

// 2nd 
int TripleNum(int *num)
{
  return (*num) * 3;
  }       

// 3rd
int* TimesThree(int &num)
{
  int* ptr = &num;
  num *= 3;
  // cout << ptr << endl;
  return ptr; 
}

// 4th
int* TripleNum(int num) const
{
  int* ptr = new int; 
  *ptr = num * 3;
  // cout << *ptr << endl;
  return ptr;
}

// 5th 
class Cop3530
{  
private:
    
    string session = "";             //stores session, example: Summer2020
    int numberOfStudents = -1;       //stores total number of students in the session

public:
    
    Cop3530();                  
    Cop3530(string session, int numberOfStudents);
    
    //accessors and mutators for session
    void setSession(string session); 
    string getSession(); 
    
    //accessors and mutators for getNumberOfStudents
    void setNumberOfStudents(int numberOfStudents); 
    int getNumberOfStudents();

};

Cop3530::Cop3530()
{
    //default constructor sets session to "Summer2020" and numberOfStudents to 150
  this->session = "Summer2020";
  this->numberOfStudents = 150;
}

Cop3530::Cop3530(string session, int numberOfStudents)
{
    //parameterized constructor sets session and numberOfStudents 
  this->session = session;
  this->numberOfStudents = numberOfStudents;
}

void Cop3530::setSession(string s)
{
    // mutator for session
  this->session = s;
}

string Cop3530::getSession()
{
    //accessor for session
  return this->session;
}

void Cop3530::setNumberOfStudents(int n)
{
    //mutator for NumberOfStudents
  this->numberOfStudents = n;
}

int Cop3530::getNumberOfStudents()
{
    //accessor for NumberOfStudents
  return this->numberOfStudents;
}
        
// 6th 
template <typename T, typename N>
N ProductOfThree(T num)
{
      //your code here
    num *= 3;
    return num;
}

// 7th 
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

// 8th 
bool arePermutations(std::vector<std::string> strs) {
    // Your code here
    set<char> tempSet; 
    int lengthFirst = strs[0].length();
    // cout << lengthFirst << endl;
  
  for (int i = 0; i < lengthFirst; i++) {
    tempSet.insert(strs[0][i]);
  }
  
  for(int i = 1; i < strs.size(); i++ ) {
    if (strs[i].length() != lengthFirst) { // length check
      return false; 
    }
    
    for(int j = 0; j < strs[i].length(); j++) {
        if( !( tempSet.find(strs[i][j]) != tempSet.end() ) ) {
          return false;
        } 
    }
    
  }
    return true;
}

// 9th 

// 10th 
