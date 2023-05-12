// A Clique is a subgraph of graph such that all vertices in subgraph are completely connected with each other.

// https://www.codingninjas.com/codestudio/problems/two-cliques_1214524
// https://www.geeksforgeeks.org/two-clique-problem-check-graph-can-divided-two-cliques/
// Approach: Construct complementary graph, If it is bipartite, then we can divide graph into two clique 

bool bfs(int node, vector<int>adj[], vector<int> &color) {
	queue<int> q;
	q.push(node);
	color[node] = 0;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		int currColor = color[x];
		for(auto neighbour : adj[x]) {
			if(color[neighbour] != -1) {
				if(color[neighbour] == currColor) return false;
			} else {
				// Assign currColor opposite color to neighbour
				color[neighbour] = currColor == 0 ? 1 : 0;
				q.push(neighbour);
			}
		}
	}
	return true;
}
bool isBipartite(int V, vector<int>adj[]) {
	// -1 -> no color, 0/1 are available two colors
	vector<int> color(V, -1); 
	for(int i = 0; i < V; i++) {
		if(color[i] == -1) {
			if(bfs(i, adj, color) == false) {
				return false;
			}
		}
	}
	return true;
}

bool twoCliques(int n, vector<vector<int>> &edgeList)
{
	// Constructing graph
	vector<vector<int>> graph(n, vector<int>(n, 0));
	for(auto i:edgeList) {
		int u = i[0];
		int v = i[1];
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	// Constructing complementary graph
	vector<int> complementaryGraph[n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) {
				continue;
			}
			if(graph[i][j] != 1) {
				complementaryGraph[i].push_back(j);
				complementaryGraph[j].push_back(i);
			}
		}
	}
	if(isBipartite(n, complementaryGraph)) {
		return true;
	} else {
		return false;
	}
}