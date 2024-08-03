#include <bits/stdc++.h>
using namespace std;
#define ll long long

class dsu {
public:
	vector<int> parent, rank;
	dsu(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1, 1);
		for (int i = 0; i <= n; ++i)
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int get(int u) { // Get the leader of u
		if (parent[u] == u)  return u;

		return parent[u] = get(parent[u]);  // path compression
	}

	void union_set(int u, int v) {
		int leader_u = get(u);
		int leader_v = get(v);

		if (leader_u != leader_v) {
			if (rank[leader_v] > rank[leader_u]) {
				swap(leader_u, leader_v);
			}

			parent[leader_v] = leader_u;
			if (rank[leader_u] == rank[leader_v]) {
				rank[leader_u]++;
			}
		}
	}

};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, edges;
	cin >> n >> edges;
	dsu d(n);

	for (int i = 0; i < edges; ++i)
	{
		ll u, v; cin >> u >> v;
		int leader_u = d.get(u);
		int leader_v = d.get(v);
		if (leader_u == leader_v) {
			cout << "Cycle\n";
			return 0;
		}
		d.union_set(u, v);
	}
	cout << "No Cycle\n";



	return 0;
}
















