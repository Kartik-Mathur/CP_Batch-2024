#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {

	multimap<int, string> m;

	m.insert({10, "Aman"});
	m.insert({11, "Abhi"});
	m.insert({11, "Abhishek"});
	m.insert({12, "Apurv"});
	// m[12] = "Himank";
	// m.insert({12, "Himank"});
	m.insert({14, "Jai"});
	m.insert({15, "Tanish"});

	auto it = m.lower_bound(12);
	auto it2 = m.upper_bound(12);

	// for (auto p : m) {
	// 	cout << p.first << ", " << p.second << endl;
	// }
	// cout << endl;

	// cout << it->first << ", " << it->second << endl;
	// cout << it2->first << ", " << it2->second << endl;

	for (auto x = it ; x != it2 ; x++) {
		cout << x->first << ", " << x->second << endl;
	}


	return 0;
}
















