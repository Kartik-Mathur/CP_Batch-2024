#include <iostream>
using namespace std;

class dsu {
public:
	vector<int> parent;
	dsu(int n) {
		parent.resize(n + 1);
		for (int i = 0; i <= n; ++i)
		{
			parent[i] = i;
		}
	}

	int get(int u) { // Get the leader of u
		if (parent[u] == u)  return u;

		return get(parent[u]);
	}

	void union_set(int u, int v) {
		int leader_u = get(u);
		int leader_v = get(v);

		if (leader_u != leader_v) {
			parent[leader_v] = leader_u;
		}
	}

};

int main() {


	return 0;
}
















