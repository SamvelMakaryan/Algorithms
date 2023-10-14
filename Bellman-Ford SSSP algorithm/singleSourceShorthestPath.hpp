#ifndef SINGLESOURCESHORTHESTPATH_HPP_
#define SINGLESOURCESHORTHESTPATH_HPP_

#include <vector>
#include <limits>

std::vector<double> singleSourceShortestPath(int src, std::vector<std::vector<std::pair<int, int>>> graph) {
    std::vector<double> distances(graph.size(), std::numeric_limits<double>::infinity());
    distances[src] = 0;
    for (int i = 1; i < graph.size(); ++i) {
        for (int j = 0; j < graph.size(); ++j) {
            for (auto [v, w] : graph[j]) {
                if (distances[v] > distances[j] + w) {
                    distances[v] = distances[j] + w;
                }
            }
        }
    }
    for (int i = 0; i < graph.size(); ++i) {
        for (auto [v, w] : graph[i]) {
            if (distances[v] > distances[i] + w) {
                distances[v] = -std::numeric_limits<double>::infinity();
            }
        }
    }
    return distances;
}

//Time complexity O(V^3)
//Space complexity O(V)
//Where V is number of vertexes and E is number of edges

#endif //SINGLESOURCESHORTHESTPATH_HPP_