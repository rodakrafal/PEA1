#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP
#include <string>

#include "Graph.hpp"

class BrutForce{
    private:
    void permutation(int *arr, int x, int y,Graph &graph, int &z, int *arr2);
    void swap(int &a, int &b);
    public:
    BrutForce();
    ~BrutForce();
    void brutForce(Graph &graph);
};
#endif