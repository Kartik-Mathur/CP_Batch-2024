#include <iostream>
using namespace std;

void solve(char *a, int i, int open, int close, int n) {
	// base case
	if (i == 2 * n) {
		a[i] = '\0';
		cout << a << endl;
		return;
	}
	// recursive case
	if (open < n) {
		a[i] = '(';
		solve(a, i + 1, open + 1, close, n);
	}
	if (close < open) {
		a[i] = ')';
		solve(a, i + 1, open, close + 1, n);
	}
}

int main() {

	int n; cin >> n;
	char a[1999];
	solve(a, 0, 0, 0, n);


	return 0;
}
















