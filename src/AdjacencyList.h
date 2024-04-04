#ifndef PAGERANK_ADJACENCYLIST_H
#define PAGERANK_ADJACENCYLIST_H


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class AdjacencyList {
private:
    //map<from, vector<pair<to, out_degree>>>
    map<string, vector<pair<string,float>>> adjacencyList;
    // map<URL, rank>
    map<string, float> ranks;
    map<string, float> oldRanks;
public:
    void insertVector(string from, string to);  // Inserts into adjacencyList, and out degree = 1.0
    void initializeGraph();  // Assigns proper out degrees and assigns ranks to r(0)
    void powerIterate(int n);  // Power iterates n times
    void printPageRank();
};
// prints the PageRank of all pages after p powerIterations in ascending alphabetical order of webpages and rounding rank to two decimal places


#endif //PAGERANK_ADJACENCYLIST_H
