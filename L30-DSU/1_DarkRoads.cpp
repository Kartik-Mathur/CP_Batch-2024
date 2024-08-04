#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;

class dsu {
public:
	vector<ll> parent, rank;
	dsu(ll n) {
		parent.resize(n + 1);
		rank.resize(n + 1, 1);
		for (ll i = 0; i <= n; ++i)
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}

	ll get(ll u) { // Get the leader of u
		if (parent[u] == u)  return u;

		return parent[u] = get(parent[u]);  // path compression
	}

	void union_set(ll u, ll v) {
		ll leader_u = get(u);
		ll leader_v = get(v);

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
	cin >> n >> m;

	while (n and m) {
		vector<vector<ll> > edges;
		ll totalWeight = 0;

		for (ll i = 0; i < m; ++i)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			edges.push_back({w, u, v});
			totalWeight += w;
		}

		sort(edges.begin(), edges.end());

		dsu d(n);
		ll ans = 0;
		for (auto node : edges) {
			ll wt = node[0];
			ll u = node[1];
			ll v = node[2];

			ll leader_u = d.get(u);
			ll leader_v = d.get(v);
			if (leader_u != leader_v) {
				d.union_set(leader_u, leader_v);
				ans += wt;
			}
		}
		cout <<  totalWeight - ans << endl;


		cin >> n >> m;
	}


	return 0;
}
















