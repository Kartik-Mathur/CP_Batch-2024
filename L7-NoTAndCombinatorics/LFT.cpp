#include <iostream>
using namespace std;


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
	// cout << x << ", " << y << endl;
	return g;
}

int linearDiophantine(int g, int c, int x, int y) {
	int xo = (x * c) / g;
	int yo = (y * c) / g;
	cout << xo << ", " << yo << endl;
	return -1;
}


int main() {
	int x, y;
	int ans = extendedEuclid(64, 40, x, y);
	// 64*x + 40*y = gcd(64,40);
	// cout << x << ", " << y << endl;
	linearDiophantine(ans, 800, x, y);



	return 0;
}
















