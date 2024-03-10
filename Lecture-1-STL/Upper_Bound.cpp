#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 8, 10};
	int n = sizeof(a) / sizeof(int);

	// lower_bound:lower_bound(a,a+n,value);
	// upper_bound:upper_bound(a,a+n,value);

	auto lb = lower_bound(a, a + n, 106);
	int indx =  (lb - a);

	if (indx < n) {
		cout << "Mill gaya\n";
	}
	else {
		cout << "Nahi Milla\n";
	}

	return 0;
}
















