#include <bits/stdc++.h>
using namespace std;
vector<int> order;
map<int, int> leader;
vector<int> leader_nodes;
void dfs(int src, vector<int> x[], bool *visited) {
	visited[src] = true;
	for (auto child : x[src]) {
		if (!visited[child]) dfs(child, x, visited);
	}
	order.push_back(src);
}

void dfsR(int src, int l, vector<int> x[], bool *visited) {
	visited[src] = true;
	leader[src] = l;

	for (auto child : x[src]) {
		if (!visited[child]) {
			dfsR(child, l, x, visited);
		}
	}
}

void kosaraju(vector<int> g[], vector<int> rg[], int N) {
	// 1. DFS on normal graph
	bool visited[100005] = {0};


	for (int i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i, g, visited);
	}
	// 2. find the reverse graph
	// We already have it

	// 3. DFS on reverse graph
	bool reverse_visited[100005] = {0};
	int component = 0;

	for (int i = order.size() - 1 ; i >= 0 ; i--) {

		if (!reverse_visited[order[i]]) {
			int l = order[i];
			leader_nodes.push_back(l);
			dfsR(order[i], l, rg, reverse_visited);
			component++;
		}
	}

	// Print the leaders
	// for (auto n : leader) {
	// 	cout << n.first << " : " << n.second << endl;
	// }
	// for (auto n : leader_nodes) {
	// 	cout << n << endl;
	// }

	// Kisi bhi node ke bache ka leader alag ho gaya,
	// that means current node, candidate nahi ho skti
	vector<bool> isCandidate(N + 1, true);

	for (int i = 1; i <= N; ++i)
	{
		for (auto n : g[i]) {
			if (leader[n] != leader[i]) {
				isCandidate[i] = false;
				break;
			}
		}
	}

	// Finding the candidates
	vector<int> candidates;
	for (auto n : leader_nodes) {
		if (isCandidate[n] == true) {
			for (int i = 1 ; i <= N ; i++) {
				if (leader[i] == leader[n]) {
					candidates.push_back(i);
				}
			}
		}
	}

	sort(candidates.begin(), candidates.end());
	cout << candidates.size() << endl;
	for (auto x : candidates) {
		cout  << x << " ";
	}
	cout  << endl;
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
















