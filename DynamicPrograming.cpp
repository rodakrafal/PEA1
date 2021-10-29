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
    int n = graph.getVertices();

    string key;
    pair<double, int> value, best;
    int bits, previous;

    for(int i = 0; i < n; ++i){
        key = to_string(1 << i) + to_string(i);
        value = make_pair(graph.getTableValue(0,i), 0);
        matrix_map[key] = value;
    }

    for(int size = 2; size < n; ++size ){
        for(auto set : combinations(1, n, size) ){
            bits = 0;
            //na 2^0 + 2^4 + 2^5 = 1001
            for(auto bit: set){
                bits |= 1 << bit;
            }

            for(auto first_loop : set){
                previous = bits & ~(1 << first_loop);
                best = make_pair(numeric_limits<int>::max(), 0);
                for(auto second_loop : set){
                    if(first_loop == second_loop){
                        continue;
                    }
                    key = to_string(previous) + to_string(second_loop);
                    value = make_pair(matrix_map[key].first + graph.getTableValue(second_loop,first_loop), second_loop);
                    best = (best.first < value.first) ? best : value;
                }
                key = to_string(bits) + to_string(first_loop);
                matrix_map[key] = best;
            }
        }
    }
    bits = (1 << n) - 2;
    best = make_pair(numeric_limits<int>::max(), 0);

    for(int i = 1; i < n; ++i){
        key = to_string(bits) + to_string(i);
        value = make_pair(matrix_map[key].first + graph.getTableValue(0,i), i);
        best = (best.first < value.first) ? best : value;
    }

    std::vector <int> path(n+1, 0);
    value = best;
    for(int i = 1; i < n; ++i){
        path[i] = value.second;
        key = to_string(bits) + to_string(path[i]);
        value = matrix_map[key];
        bits = bits & ~(1 << path[i]);
    }

    for(int i = n; i >= 0 ; --i){
        cout << path[i] << " ";
    }
    cout << "\n" << best.first << endl;

}

 vector<vector<int>> DynamicPrograming::combinations(int start, int end, int r){
        vector<vector<int>> combinations;

        int n = end - start;

        vector<bool> vertex(n);
        fill(vertex.end() - r, vertex.end(), true);

        do{
            vector<int> line;
            for(int i = 0; i < n; ++i){
                if(vertex[i]){
                    line.push_back(i+start);
                }
            }
            combinations.push_back(line);
        }while(next_permutation(vertex.begin(), vertex.end()));

        return combinations;
    }