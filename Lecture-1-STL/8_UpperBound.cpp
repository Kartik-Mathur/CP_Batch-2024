#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v = {6, 6, 6, 7, 7, 8, 10};

	auto it = lower_bound(v.begin(), v.end(), 9);
	bool ans = binary_search(v.begin(), v.end(), 9);
	if (ans == true) {
		cout << "9 Found\n";
	}
	else {
		cout << "Not Found 9\n";
	}
	if (it != v.end()) {
		cout << *it << endl;
		cout << "Index " << it - v.begin() << endl;
	}
	else
		cout << "Not Found";



	return 0;
}
















