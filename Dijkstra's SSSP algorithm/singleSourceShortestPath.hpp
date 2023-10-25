#ifndef SINGLESOURCESHORTESTPATH_HPP_
#define SINGLESOURCESHORTESTPATH_HPP_

#include <vector>
#include <limits>
#include <queue>

    std::vector<int> singleSourceSHortestPath(int src, std::vector<std::vector<std::pair<int, int>>> graph) {
		std::vector<int> distance(graph.size(), std::numeric_limits<int>::max());
		distance[src] = 0;
		auto comparator = [](const auto& p1, const auto& p2){return p1.second < p2.second;};
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comparator)> pq(comparator);
		pq.push({src, 0}); 
		while (!pq.empty()) {
			auto [v, w] = pq.top();
			pq.pop();
			if (w > distance[v]) {
				continue;
			}
			for (auto [u, w2] : graph[v]) {
				if (distance[v] + w2 < distance[u]) {
					distance[u] = distance[v] + w2;
					pq.push({u, distance[u]});
				}
			}
		}
		return distance;
	}

//Time complexity O((V + E) * log(V))
//Space complexity O(V)
//Where V is number of vertexes and E is number of edges

#endif //SINGLESOURCESHORTESTPATH_HPP_