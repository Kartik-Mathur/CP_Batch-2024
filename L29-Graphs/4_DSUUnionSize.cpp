#include <iostream>
using namespace std;

class dsu {
public:
	vector<int> parent, size;
	dsu(int n) {
		parent.resize(n + 1);
		size.resize(n + 1, 1);

		for (int i = 0; i <= n; ++i)
		{
			parent[i] = i;
			size[i] = 1;
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
			if (size[leader_v] > size[leader_u]) {
				swap(leader_v, leader_u);
			}

			parent[leader_v] = leader_u;
			size[leader_u] += size[leader_v];
		}
	}

};

int main() {


	return 0;
}
















