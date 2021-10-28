#include "DynamicPrograming.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

void DynamicPrograming::heldKarp(Graph &graph){
    // mapInfo mapInfo = {1,23};
    // pair<int,int> key = {9,2};
    // umap.insert({key,mapInfo});

    // auto search = this->umap.find(key);
    // if (search != umap.end()) {
    //     cout << "Found " << to_string(search->first.first) + " " + to_string(search->first.second)  + " " << search->second.weight << " " << search->second.penultimateVerticie <<'\n';
    // } else {
    //     cout << "Not found\n";
    // }
    pair<int,int> key;
    int n = graph.getVertices();
    int value, best = numeric_limits<int>::max();
    int temp, bits = 0;
    for (int i = 1; i <= n; i++){
        umap.insert({{1<<i,i},graph.getTableValue(0,i)});
    }

    for (int setSize = 2; setSize < n; setSize++){
        for (auto set : combinations(n, setSize)){
            for (int i = 0; i < n;i++){
                if(i & set){
                    best = numeric_limits<int>::max();
                    key = {set,i};
                    for (int j = 1; j<n;j++){
                        if(!(j & set)){
                            auto search = this->umap.find(key);
                            if (search != umap.end()) {
                                value = search->second + graph.getTableValue(i,j);
                                best = (best < value) ? best : value;
                                temp = j;
                            } 
                            // else {
                            //     key = {set,i};
                            //     umap[key] = best;
                            // }
                        }          
                    }
                bits = set |= 1 << i;
                key = {set |= 1 << i,temp};
                umap[key] = best;
            }
        }
    }
    }
    
    // bits = (1 << n) - 2;
    // for(int i = 1; i < n; i++){
    //     key = {bits |= 1 << i,i};
    //     value = make_pair(matrix_map[key].first + matrixStructure.matrix[i][0], i);
    //     best = (best.first < value.first) ? best : value;
    //     cout << "V: " << key << " : " << value.first << " - " << value.second << endl;
    // }

}


vector<int> DynamicPrograming::combinations(int end, int r){
        // wektor z kombinacjami do zwrocenia
        vector<int> combinations;

        // liczba wartosci do przypisania
        int n = end - 1;

        // wektor 
        vector<bool> vertex(n);
        // przypisanie wartosci w zakresie (pierwsza, ostatnia, wartosc)
        fill(vertex.end() - r, vertex.end(), true);

        do{
            // tymaczasowy wektor liczb 
            int bits = 0;
            for(int i = 0; i < n; i++){
                if(vertex[i]){
                    bits |= 1 << i;
                }
            }
            // zapisanie kombinacji do wyniku
            combinations.push_back(bits);
        // wyliczenie kolejnej permutacji
        }while(next_permutation(vertex.begin(), vertex.end()));

        // zwróć kombinacje
        return combinations;
    }