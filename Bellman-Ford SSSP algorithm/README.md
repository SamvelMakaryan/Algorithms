This is Richard Bellman and Lester Ford Jr. algorithm for SSSP. This algarithms detects all negative cycles and impacted vertexes.
It returns an vector of distances where if there is no path the value is +infinity and if negative cycle is detected -infinty for the remaining vertices the value is the sum of wightes in that path.