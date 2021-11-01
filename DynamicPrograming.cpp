#include "DynamicPrograming.hpp"
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

void DynamicPrograming::heldKarp(Graph &graph){

    int firstVertice = graph.getVertices()-1;
    // number of vertices except the first one 
    int numberOfMidpathCities = graph.getVertices()-1;
    // binary shift giving the total number of vertices in the path
    int numberOfSubsets = 1 << numberOfMidpathCities;
    int allMidpathCities  = (1 << numberOfMidpathCities)-1;

    MapInfo mapInfo;
    pair<int,int> key;
    for (int i = 0; i < numberOfMidpathCities; i++) {
			mapInfo.parent = firstVertice;
			mapInfo.weight = graph.getTableValue(firstVertice,i);
			umap.insert({{0,i},mapInfo});
	}
    int minPath = INT_MAX;
    int minLastVertice = -1;

    for (int finalCity = 0; finalCity < numberOfMidpathCities; finalCity++) {
			int distance = solveSubproblem(graph, numberOfMidpathCities,(allMidpathCities & ~(1 << finalCity)), finalCity) + graph.getTableValue(finalCity, firstVertice);

			if (distance < minPath) {
				minPath = distance;
				minLastVertice = finalCity;
			}
    }

	cout << "sciezka minimalna waga: " << minPath << endl;
}

int DynamicPrograming::solveSubproblem(Graph &graph, int numberOfMidpathCities, int subset, int destCity) {
	auto search = umap.find({subset,destCity});
	if (search != umap.end()) {
		return search->second.weight;
	} else {
		int minDistance = INT_MAX;
		int minParent = -1;

		for (int preDestCity = 0; preDestCity < numberOfMidpathCities; preDestCity++) {
				if ((subset & (1 << preDestCity)) != 0) {
					int subsetWithoutPreDestCity = (subset & ~(1 << preDestCity));
					int distance = solveSubproblem(graph, numberOfMidpathCities, subsetWithoutPreDestCity, preDestCity) + graph.getTableValue(preDestCity, destCity);

					if (distance < minDistance) {
						minDistance = distance;
						minParent = preDestCity;
					}
				}
		}

		MapInfo mapInfo;
		mapInfo.weight = minDistance;
		mapInfo.parent = minParent;
		umap.insert({{subset,destCity},mapInfo});
		return minDistance;
	}
}