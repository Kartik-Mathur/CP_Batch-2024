#include <iostream>
using namespace std;

int main() {
	// auto x;
	// cout << x << endl;
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	// 1,1,1,1
	if (a >= 1 and b >= 1 and c >= 1 and (a + b + c) >= n) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	return 0;
}
















