#include "AdjacencyList.h"
#include <iomanip>
void AdjacencyList::insertVector(string from, string to) {  // O(1)
    // Base way of injecting into graph, states there is a connection
    adjacencyList[from].push_back(make_pair(to, 1.0));
    adjacencyList[to];  // in case it doesn't point to anything, need to initalize the to into the graph
}

void AdjacencyList::initializeGraph() {  // O(V + E)
    // map<from, vector<pair<to, out_degree>>>
    // map<URL, Rank>
    const float graphSize = adjacencyList.size();
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        ranks[it->first] = 1.0 / graphSize;  // r(0)
        auto& pairs = it->second;
        int out = pairs.size(); // How many nodes its pointing to
        for (auto& pair : pairs) {
            pair.second = 1.0 / out;  // Changes out degree of vector (stays permanent)
        }
    }
}

void AdjacencyList::powerIterate(int n) {
    // map<from, vector<pair<to, out_degree>>>
    // map<URL, rank>
    for (int i = 1; i < n; i++) {
        oldRanks = ranks;  // Stores previous rank, r(i-1)
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            ranks[it->first] = 0.0;  // Sets all ranks to 0 to get ready for summing
        }
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            auto pairs = it->second;
            for (auto pair : pairs) {
                ranks[pair.first] += oldRanks[it->first] * pair.second;
                // cout << it->first << " points to " << pair.first << " with out degree = " << pair.second << " and rank " << oldRanks[it->first] << endl;
            }
        }
    }
}

void AdjacencyList::printPageRank() {  // Prints site and rank rounded to two decimals
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
        cout << it->first << " " << fixed << setprecision(2) << ranks[it->first] << endl;
    }
}
