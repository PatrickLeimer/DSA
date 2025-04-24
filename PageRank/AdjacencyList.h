#pragma once

#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

class AdjacencyList {
    private:
    //Think about what member variables you need to initialize
    // Graph Represented by an Adjacency List
    map<string, vector<string>> websitesGraph;
    // Rank
    map<string, double> pageRank;
    // Set of all the unique websites
    set<string> vertex;

    public:
    AdjacencyList(const map<string, vector<string>> &sites);
    ~AdjacencyList();

    //Think about what helper functions you will need in the algorithm
    string PageRank(int n);
};
