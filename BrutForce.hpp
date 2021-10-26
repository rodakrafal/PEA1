#ifndef BRUTEFORCE_HPP
#define BRUTEFORCE_HPP
#include <string>

#include "Graph.hpp"

class BrutForce{
    private:
    void permutation(int *arr, int x, int y,Graph &graph, int &z, int *arr2); // permutation
    void swap(int &a, int &b); // swap method
    public:
    BrutForce(); // constructor
    ~BrutForce(); // destructor
    void brutForce(Graph &graph); // main method
};
#endif