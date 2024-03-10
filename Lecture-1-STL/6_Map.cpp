#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main() {

	// map<vector<string>, int> m; // Self Balancing Tree
	map<string, int> m; // Self Balancing Tree
	// unordered_map<string, int> m; // Self Balancing Tree
	// Insertion time: O(logN)

	m.insert({"Mango", 100});
	m.insert(make_pair("Kiwi", 50));

	pair<string, int> p = {"Pineapple", 140};
	m.insert(p);

	pair<string, int> p1({"Guava", 40});
	m.insert(p1);

	auto x = m.find("Pineapple");
	if (x != m.end())
		cout << x->first << ", " << x->second << endl;
	else
		cout << "Not Found\n";


	// for (auto p : m) {
	// 	cout << p.first << ", " << p.second << endl;
	// }

	return 0;
}
















