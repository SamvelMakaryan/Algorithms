#ifndef STRONGLYCONNECTEDCOMPONENTS_HPP_
#define STRONGLYCONNECTEDCOMPONENTS_HPP_

#include <vector>
#include <stack>

std::vector<std::vector<int>> scc(std::vector<std::vector<int>>& graph) {
    std::vector<int> ids(graph.size(), -1);
    std::vector<int> low(graph.size(), -1);
    std::vector<bool> inStack(graph.size(), false);
    std::vector<std::vector<int>> result;
    std::stack<int> s;
    int id = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (ids[i] == -1) {
            sccHelper(i, ids, low, inStack, graph, s, result, id);
        }
    }
    return result;
}

void sccHelper(int v, std::vector<int>& ids, std::vector<int>& low, std::vector<bool>& inStack, std::vector<std::vector<int>>& graph, 
                                            std::stack<int>& s, std::vector<std::vector<int>>& result, int& id) {
    ids[v] = id;
    low[v] = id++;
    inStack[v] = true;
    s.push(v);
    for (auto i : graph[v]) {
        if (ids[i] == -1) {
            sccHelper(i, ids, low, inStack, graph, s, result, id);
        }
        if (inStack[i]) {
            low[v] = std::min(low[v], low[i]); 
        }
    }
    if (low[v] == ids[v]) {
        std::vector<int> cur;
        int tmp;
        do {
            tmp = s.top();
            s.pop();
            inStack[tmp] = false;
            cur.push_back(tmp);
        } while (tmp != v);
        result.push_back(cur);
    }
}

//Time complexity O(V + E)
//Space complexity O(V)
//Where V is number of vertexes and E is number of edges

#endif //STRONGLYCONNECTEDCOMPONENTS_HPP_