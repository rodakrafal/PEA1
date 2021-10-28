#ifndef DYNAMICPROGRAMING_HPP
#define DYNAMICPROGRAMING_HPP
#include "Graph.hpp"
#include <unordered_map>

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
    std::vector<int> combinations(int end, int r);
    std::unordered_map<pairKey,int,pair_hash> umap; // basically a hash map
    public: 
    void heldKarp(Graph &graph); // main metod
};
#endif