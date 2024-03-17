#include <iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int a[] = {1, 10, 2, 5, 5, 4, 2, 1};
	int n = sizeof(a) / sizeof(int);
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		ans ^= a[i];
	}

	cout << ans << endl;

	// Find the single set bit number in answer
	int x = 1;
	while ((ans & x) == 0)
		x <<= 1;

	cout << x << endl;

	// Finding one unique number
	int no1 = 0;
	for (int i = 0; i < n; ++i)
	{
		if ( (a[i]&x) == 0) {
			no1 ^= a[i];
		}
	}
	cout << no1 << ", " << (no1 ^ ans) << endl;

	return 0;
}
















