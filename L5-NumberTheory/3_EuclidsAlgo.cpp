#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (!b) return a;

	return gcd(b, a % b);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int gcdans = gcd(n, m);
	cout << gcdans << endl;
	int lcm = (n * m) / gcdans;
	cout << lcm << endl;

	return 0;
}
















