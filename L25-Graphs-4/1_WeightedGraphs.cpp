#include <iostream>
#include <map>
#include <set>
#include <list>
using namespace std;

template<typename T>
class Graph {
public:
	map<T, list<pair<T, int> > > adj;

	void addEdge(T u, T v, int d, bool bidir = true) {
		adj[u].push_back({v, d});
		if (bidir) adj[v].push_back({u, d});
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << "-> ";
			for (auto neighbour : p.second) {
				cout << "(" << neighbour.first << ", " << neighbour.second << ") ";
			}
			cout << endl;
		}
	}

	void dijkstras(T src, T des) {

		map<T, int> dist;
		map<T, T> parent;

		for (auto n : adj) {
			dist[n.first] = INT_MAX;
		}

		dist[src] = 0;
		parent[src] = src;

		set<pair<int, T> > s;
		s.insert({0, src});

		while (!s.empty()) {
			auto x = *s.begin();
			s.erase(s.begin());

			int currentDistance = x.first;
			for (auto neighbour : adj[x.second]) {
				int edgeDistance = neighbour.second;
				T child = neighbour.first;

				if (dist[child] > currentDistance + edgeDistance) {
					// If set ke andar already child present hai, toh delete karo
					// dobara insert kardo, distance update karke
					auto p = s.find({dist[child], child});
					if (p != s.end()) {
						s.erase(p);
					}

					// update karo distance ko
					dist[child] = currentDistance + edgeDistance;
					parent[child] = x.second;
					s.insert({dist[child], child});
				}
			}
		}


		// Print shortest distance from src
		for (auto p : dist) {
			cout << "Distance of " << p.first << " from " << src << " " << p.second << endl;
		}

		// Printing the path till destination
		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;
	}

};

int main() {


	Graph<string> g;
	g.addEdge("A", "B", 1);
	g.addEdge("A", "C", 8);
	g.addEdge("A", "D", 4);
	g.addEdge("B", "D", 2);
	g.addEdge("C", "D", 3);

	// g.print();
	g.dijkstras("A", "C");

	return 0;
}
















