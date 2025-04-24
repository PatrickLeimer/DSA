#include <iostream>

#include "AdjacencyList.h"
#include <map>
using namespace std;

int main() {

    // map for input
     map<string, vector<string>> fromToInput;
     int no_of_lines, power_iterations;
     string from, to;

     cin >> no_of_lines;
     cin >> power_iterations;
         for (int i = 0; i < no_of_lines; i++) {
         cin >> from;
         cin >> to;
         // Do Something
         fromToInput[from].push_back(to);
     }

    AdjacencyList adjacencyList(fromToInput);
    cout << adjacencyList.PageRank(power_iterations);

}
