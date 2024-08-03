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
	for (auto child : x[src]) {
		if (!visited[child]) dfsR(child, x, visited);
	}
}

void kosaraju(vector<int> g[], vector<int> rg[], int N) {
	// 1. DFS on normal graph
	bool visited[105] = {0};

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i, g, visited);
	}
	// 2. find the reverse graph
	// We already have it

	// 3. DFS on reverse graph
	bool reverse_visited[105] = {0};
	int component = 0;

	for (int i = order.size() - 1 ; i >= 0 ; i--) {

		if (!reverse_visited[order[i]]) {
			dfsR(order[i], rg, reverse_visited);
			component++;
		}
	}
	cout << component << endl;

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int N;
		cin >> N;

		vector<int> g[101];
		vector<int> rg[101];

		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				char ch; cin >> ch;
				if (ch == 'Y') {
					g[i].push_back(j);
					rg[j].push_back(i);
				}
			}
		}

		kosaraju(g, rg, N);
		order.clear();
	}


	return 0;
}
















