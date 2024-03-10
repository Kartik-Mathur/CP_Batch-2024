#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	cout << "Comparing " << a << " and " << b << endl;
	return a < b;
}

int main() {
	vector<int> v = {4, 5, 3, 2, 1};

	// sort(v.begin(), v.end(), greater<int>());
	// sort(v.begin(), v.end(), compare);

	sort(v.begin(), v.end(), [](int &a, int &b) {
		return a > b;
	});

	for (int data : v) {
		cout << data << " ";
	}
	cout << endl;

	return 0;
}
















