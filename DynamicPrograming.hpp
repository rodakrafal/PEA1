#ifndef DYNAMICPROGRAMING_HPP
#define DYNAMICPROGRAMING_HPP
#include "Graph.hpp"
#include <unordered_map>

struct mapInfo{ // details that are stored in the hash map
    int weight;
    int penultimateVerticie ;
};

typedef std::pair<int,int> pairKey;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pairKey) const
    {
        return std::hash<T1>()(pairKey.first) ^ std::hash<T2>()(pairKey.second);
    }
};

class DynamicPrograming{
    private:
    std::unordered_map<pairKey,mapInfo,pair_hash> umap; // basically a hash map
    public: 
    void heldKarp(Graph &graph); // main metod
};
#endif