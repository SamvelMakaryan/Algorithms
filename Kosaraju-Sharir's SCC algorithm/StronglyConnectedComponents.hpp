#ifndef STRONGLYCONNECTEDCOMPONENTS_HPP_
#define STRONGLYCONNECTEDCOMPONENTS_HPP_

#include <algorithm>
#include <vector>
#include <stack>

void dfs(int v, std::vector<bool>& visited, std::stack<int>& s, std::vector<std::vector<int>>& graph) {
    visited[v] = true;
    for (auto i : graph[v]) {
        if (!visited[i]) {
            dfs(i, visited, s, graph);
        }
    }
    s.push(v);
}

void dfs(int v, std::vector<bool>& visited, std::vector<int>& component, std::vector<std::vector<int>>& reversed) {
    visited[v] = true;
    component.push_back(v);
    for (auto i : reversed[v]) {
        if (!visited[i]) {
            dfs(i, visited, component, reversed);
        }
    }
}

void transpose(std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> tmp(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        for (auto v : graph[i]) {
            tmp[v].push_back(i);
        }
    }
    graph = tmp;
}

std::vector<std::vector<int>> scc(std::vector<std::vector<int>>& graph) {
    std::stack<int> s;
    std::vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            dfs(i, visited, s, graph);
        }
    }
    std::vector<std::vector<int>> result;
    std::fill(visited.begin(), visited.end(), false);
    auto reversed(graph);
    transpose(reversed);
    while (!s.empty()) {
        int tmp = s.top();
        s.pop();
        if (!visited[tmp]) {
            std::vector<int> component;
            dfs(tmp, visited, component, reversed);
            result.push_back(component);
        }
    }
    return result;
}

//Time complexity O(V + E)
//Space complexity O(V)
//Where V is number of vertexes and E is number of edges

#endif //STRONGLYCONNECTEDCOMPONENTS_HPP_