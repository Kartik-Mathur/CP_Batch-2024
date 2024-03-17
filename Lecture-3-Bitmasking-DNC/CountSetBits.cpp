#include <iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	cout << __builtin_popcount(n) << endl;

	int cnt = 0;
	while (n) {
		n = n & (n - 1);
		cnt++;
	}
	cout << cnt << endl;


	return 0;
}
















