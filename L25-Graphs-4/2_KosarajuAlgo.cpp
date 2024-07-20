#include <bits/stdc++.h>
using namespace std;
vector<int> order;

void dfs(int src, vector<int> x[], bool *visited) {
	visited[src] = true;
	for (auto child : x[src]) {
		if (!visited[child]) dfs(child, x, visited);
	}
	order.push_back(src);
}

void dfsR(int src, vector<int> x[], bool *visited) {
	visited[src] = true;
	cout << src << " ";
	for (auto child : x[src]) {
		if (!visited[child]) dfsR(child, x, visited);
	}
}

void kosaraju(vector<int> g[], vector<int> rg[], int N) {
	// 1. DFS on normal graph
	bool visited[100000] = {0};


	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i, g, visited);
	}
	// 2. find the reverse graph
	// We already have it

	// 3. DFS on reverse graph
	bool reverse_visited[100000] = {0};
	int component = 1;

	for (int i = order.size() - 1 ; i >= 0 ; i--) {

		if (!reverse_visited[order[i]]) {
			cout << "Component " << component << " : ";
			dfsR(order[i], rg, reverse_visited);
			cout << endl;
			component++;
		}


	}

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N, edges, u, v;
	cin >> N;

	vector<int> g[N + 1];
	vector<int> rg[N + 1];
	cin >> edges;

	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}

	kosaraju(g, rg, N);


	return 0;
}
















