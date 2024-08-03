#include <iostream>
using namespace std;

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


	return 0;
}
















