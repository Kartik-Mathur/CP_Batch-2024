#include <iostream>
#include <set>
using namespace std;

class compare {
public:
	bool operator()(const pair<string, int> &p1,
	                const pair<string, int> &p2) const {
		return p1.second < p2.second;
	}
};

int main() {
	// set<int> s;
	// s.insert(1);
	// s.insert(1);
	// s.insert(1);
	// s.insert(1);
	// s.insert(4);
	// s.insert(2);
	// s.insert(3);
	// s.insert(5);
	// s.insert(6);

	set<pair<string, int>, compare > s;
	// set<pair<string, int> >::iterator it;

	s.insert({"Himank", 100});
	s.insert({"Himank", 100});
	s.insert({"Abhay", 50});
	s.insert({"Mridul", 150});

	for (auto x : s) {
		cout << x.first << ", " << x.second << endl;
	}

	// for (it = s.begin() ; it != s.end() ; it++) {
	// 	cout << it->first << ", " << it->second << endl;
	// }

	return 0;
}
















