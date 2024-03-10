#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v = {1, 2, 3, 4, 5, 6};
	// n*m with every value as 0
	// vector<vector<int > > v(n , vector<int>(m, 0));
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v.pop_back();

	reverse(v.begin(), v.end());

	// For every data that belongs to vector v
	for (int data : v) {
		cout << data << " ";
	}
	cout << endl;


	return 0;
}
















