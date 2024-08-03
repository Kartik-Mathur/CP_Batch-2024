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

	vector<vector<int> > edges = {
		{1, 1, 2},
		{2, 3, 2},
		{3, 3, 4},
		{8, 1, 4},
		{1, 4, 5},
		{14, 5, 3}
	};

	sort(edges.begin(), edges.end());

	dsu d(5);
	int ans = 0;
	for (auto n : edges) {
		ll wt = n[0];
		ll u = n[1];
		ll v = n[2];

		int leader_u = d.get(u);
		int leader_v = d.get(v);
		if (leader_u != leader_v) {
			d.union_set(leader_u, leader_v);
			ans += wt;
		}
	}

	cout << "MST : " << ans << endl;



	return 0;
}
















