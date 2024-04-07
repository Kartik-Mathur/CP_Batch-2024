#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;

	return gcd(b, a % b);
}

int extendedEuclid(int a, int b, int &x, int &y) {
	// base case
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	// recursive case
	int xd, yd;
	int g = extendedEuclid(b, a % b, xd, yd);
	x = yd;
	y = xd - (a / b) * yd;
	return g;
}

int modularInverse(int n, int m) {
	int x, y;
	int ans = extendedEuclid(n, m, x, y);
	return (x + m) % m;
}

int main() {

	cout << modularInverse(7, 9) << endl;
	return 0;
}
















