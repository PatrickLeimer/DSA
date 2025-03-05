// Patrick Leimer -- Partner is -> Ilani Seguinot
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//As for the note, I will be using a 2D vector as an input, though,
//if you'd want to use 2D array, then there are various methods, including passing by reference
vector<string> bookTitleExtractor(vector<vector<string>>& bookTitles) {
  vector<string> booksReturn;
  //Use a map to avoid having to check for repeated book titles, and to sort automatically
  map<string, int> bookMap;

  //iterate through the whole collection gathering all the titles within the map
  for (int i = 0; i < bookTitles.size(); i++) {
    for (int j = 0; j < bookTitles[i].size(); j++) {
      bookMap[bookTitles[i][j]]++;
    }
  }
  //Gather all the book titles using an iterator
  for(auto it = bookMap.begin(); it != bookMap.end(); it++) {
    booksReturn.push_back(it->first);
  }

  return booksReturn;
}

//For testing purposes
int main() {
  vector<vector<string>> A = {
    {"Patrick", "Hello", "Ilani", "Seguinot", "Leimer"},
    {"Spain", "Hello", "Ate", "Patrick", "Hallo"}
  };

  auto extracted = bookTitleExtractor(A);

  for (int i = 0; i < extracted.size(); i++) {
    cout << "Book " << i+1 << ": " << extracted[i] << endl;
  }

  return 0;
}