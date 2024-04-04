#include <iostream>
#include <string>
#include "AdjacencyList.h"

using namespace std;

int main()
{
    int no_of_lines, power_iterations;
    std::string from, to;
    AdjacencyList adjacencyList;
    std::cin >> no_of_lines;
    std::cin >> power_iterations;
    for(int i = 0; i < no_of_lines; i++)
    {
        std::cin >> from;
        std::cin >> to;
        adjacencyList.insertVector(from, to);
    }
    adjacencyList.initializeGraph(); // Assigns out degrees and inital ranks
    adjacencyList.powerIterate(power_iterations);  // Power iterates
    adjacencyList.printPageRank();
}
