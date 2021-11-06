#ifndef BRANCHANDBOUND_HPP
#define BRANCHANDBOUND_HPP
#include <vector>
#include <queue>
#include "Graph.hpp"

// State Space Tree nodes
struct Node
{
    // stores edges of the state-space tree
    // help in tracing the path when the answer is found
    std::vector<std::pair<int, int>> trackpath;

    // stores the reduced matrix
    int **mtrxReduced;
 
    // stores the lower bound
    int cityNum;
    int level;
    int cost;
 
    // stores the current city number
 
    // stores the total number of cities visited so far
};

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->cost > rhs->cost;
    }
};
 

class BranchAndBound{
    private:
    void reduceRow(int**mtrxReduced, int* row, int Vnum);

    void reduceCol(int**mtrxReduced, int* col, int Vnum);

    int costFind(int** mtrxReduced, int Vnum);

    void printTrackPath(std::vector<std::pair<int, int>> const &list);
    Node* newNode(int** ancestorMtrx, std::vector<std::pair<int,int>> const &trackpath, int level, int i , int j, int Vnum );
    std::vector<std::pair<int, int>> r;
    std::priority_queue<Node*, std::vector<Node*>, comp> pq;
    public:
    void bnb(Graph &graph);
};

#endif