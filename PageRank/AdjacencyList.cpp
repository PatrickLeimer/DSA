

#include <iostream>
#include "AdjacencyList.h"
#include <sstream>
#include <iomanip>
using namespace std;

// Constructor and Destructor
AdjacencyList::AdjacencyList(const map<string, vector<string>> &sites) {
    this->websitesGraph = sites;
    // Builds the graph & the set required to rank the pages
    for (auto &site : sites) {
        vertex.insert(site.first);
        // Also add every target page in the outgoing list
        for (auto &target : site.second) {
            vertex.insert(target);
        }
    }
}
AdjacencyList::~AdjacencyList() = default;
// --------------------------------------------------------------------------------------


// PageRanking, taking input and converting it using adjacencylist graph of the class
string AdjacencyList::PageRank(int n){
    // prints the PageRank of all pages after p powerIterations in ascending
    // alphabetical order of webpages and rounding rank to two decimal places

    // Initial page ranking 1 / total count of vertex
    double initialRank = 1.0 / vertex.size(); //typecasting happening

    for (const string &site : vertex) {
        pageRank[site] = initialRank;
    }

    // Power iterations For each iteration, we distribute the current rank of each page to its neighbors
    for (int iter = 1; iter < n; ++iter) {

        map<string, double> startRank;

        for (const auto &site : vertex) {
            startRank[site] = 0.0;
        }

        for (const auto &page : websitesGraph) {
            const auto &site = page.first;
            const auto &neighbors = page.second;

            if (neighbors.empty()) continue; // check if it has neighbours
            double contribution = pageRank[site] / neighbors.size();

            for (const auto &dest : neighbors) {
                startRank[dest] += contribution;
            }
        }

        // Swap in the newly computed ranks
        pageRank.swap(startRank);

    }

    // optionally, store your output in a string/stringstream and then return it from this function after printing so that it is easier to test with Catch
    stringstream output;
    output << fixed << setprecision(2);

    for (const auto &site : vertex) {
        output << site << " " << pageRank[site] << "\n";
    }

    return output.str();

}
// --------------------------------------------------------------------------------------

