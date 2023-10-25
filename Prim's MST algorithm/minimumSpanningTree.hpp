#ifndef MINIMUMSPANNINGTREE_HPP_
#define MINIMUMSPANNINGTREE_HPP_

#include <limits>
#include <vector>
#include <queue>

int weightOfMST(std::vector<std::vector<std::pair<int, int>>>& graph) {
    std::vector<bool> visited(graph.size(), false);
    int weight = 0;
    auto comp = [](const auto& p1, const auto& p2) {return p1.second > p2.second;};
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq(comp);
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [u, w] = pq.top();
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        weight += w;
        for (auto v : graph[u]) {
            if (!visited[v.first]) {
                pq.push(v);
            }
        }
    }
    return weight;
}

//Time complexity O((V + E) * log(V))
//Space complexity O(V + E)
//Where V is number of vertexes and E is number of edges

#endif //MINIMUMSPANNINGTREE_HPP_