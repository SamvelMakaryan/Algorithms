#ifndef TOPOLOGICAL_SORT_HPP_
#define TOPOLOGICAL_SORT_HPP_

#include <stdexcept>
#include <vector>
#include <queue>

std::vector<int> topSort(std::vector<std::vector<int>>& adj) {
    std::vector<int> inDegree(adj.size(), 0);
    for (auto& vec : adj) {
        for (auto& v : vec) {
            ++inDegree[v];
        }
    }
    std::queue<int> q;
    for (int i = 0; i < adj.size(); ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    std::vector<int> sorted;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        sorted.push_back(v);
        for (auto i : adj[v]) {
            if (--inDegree[i] == 0) {
                q.push(i);
            }
        }
    }
    if (sorted.size() != adj.size()) {
        throw std::logic_error("Graph has cycle.");
    }
    return sorted;
}

//Time complexity O(V + E)
//Space complexity O(V)
//Where V is number of vertexes and E is number of edges


#endif //TOPOLOGICAL_SORT_HPP_