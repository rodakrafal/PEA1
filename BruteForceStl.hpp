#ifndef BRUTEFORCESTL_HPP
#define BRUTEFORCESTL_HPP
#include <string>
#include <vector>
#include <algorithm>

#include "Graph.hpp"

struct Result // structure for end values
{
    std::vector <int> shortestPath;
    int lowestWeight;
};

class BruteForceStl{
    public:
    void bruteForceStl(Graph &graph); // main method
};
#endif