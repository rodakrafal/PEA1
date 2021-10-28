#include "DynamicPrograming.hpp"
#include <iostream>
#include <limits>

using namespace std;

void DynamicPrograming::heldKarp(Graph &graph){
   mapInfo mapInfo = {1,23};
   pair<int,int> key = {1,2};
   umap.insert({key,mapInfo});

   auto search = this->umap.find(key);
   if (search != umap.end()) {
       cout << "Found " << to_string(search->first.first) + " " + to_string(search->first.second)  + " " << search->second.weight << " " << search->second.penultimateVerticie <<'\n';
   } else {
       cout << "Not found\n";
   }
}