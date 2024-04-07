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
	cout << x << ", " << y << endl;
	return g;
}

class Tuple {
public:
	int x, y, g;
};

Tuple eea(int a, int b) {
	// base case
	if (b == 0) {
		return {1, 0, a};
	}
	// recursive case
	Tuple prev = eea(b, a % b);
	int x = prev.y;
	int y = prev.x - (a / b) * prev.y;
	cout << x << ", " << y << endl;
	return {x, y, prev.g};
}

int main() {
	int x, y;
	// int ans = extendedEuclid(64, 40, x, y);
	Tuple t = eea(8, 5);
	cout << t.x << ", " << t.y << endl;
	// cout << "Solution: " << x << " and " << y << endl;

	return 0;
}
















