#include <iostream>
using namespace std;
int a, b, c;

int gcd(int a, int b) {
	if (b == 0) return a;

	return gcd(b, a % b);
}

int main() {
	int number = 1;
	int t; cin >> t; while (t--) {
		cin >> a >> b >> c;
		string ans;
		if (c % gcd(a, b) == 0) ans = "Yes";
		else ans = "No";

		cout << "Case " << number++ << ": " << ans << endl;
	}

	return 0;
}
















