#include <iostream>
using namespace std;

int findPivot(int *a, int n) {
	int s = 0, e = n - 1;
	if (n <= 1) return n - 1;

	if (a[s] < a[e]) return 0;

	while (s <= e) {
		int mid = s + (e - s) / 2;
		if ( (mid - 1) >= 0 and a[mid] < a[mid - 1]) return mid;
		if ( (mid + 1) < n and a[mid] > a[mid + 1]) return mid;
		else if (a[mid] >= a[n - 1]) s = mid;
		else e = mid;
	}
	return -1;
}

int main() {

	int a[] = {8, 7};
	int n = sizeof(a) / sizeof(int);

	cout << findPivot(a, n) << endl;

	return 0;
}
















