#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP

#include "Graph.hpp"

class BruteForce{
    private:
    void permutation(int *arr, int x, int y,Graph &graph, int &z, int *arr2); // permutation
    void swap(int &a, int &b); // swap method
    public:
    void bruteForce(Graph &graph); // main method
};
#endif