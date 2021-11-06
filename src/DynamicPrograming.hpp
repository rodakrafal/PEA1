#ifndef DYNAMICPROGRAMING_HPP
#define DYNAMICPROGRAMING_HPP
#include "Graph.hpp"
#include <unordered_map>
#include <vector>
typedef std::pair<int,int> pairKey;

struct pair_hash // key to the unordered map consisted of 2 integers
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pairKey) const
    {
        return std::hash<T1>()(pairKey.first) ^ std::hash<T2>()(pairKey.second);
    }
};
// information stored inside unordered map
struct MapInfo{
    int weight;
    int parent;
};

class DynamicPrograming{
    private:
    int calculateDistance(Graph &graph, int x, int y, int z); // recursion method to calculate shortest path
    std::unordered_map<pairKey,MapInfo,pair_hash> umap; // basically a hash map
    public: 
    void heldKarp(Graph &graph); // main metod
};
#endif