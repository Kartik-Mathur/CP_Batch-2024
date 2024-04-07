#include <iostream>
using namespace std;

int power(int a, int n) {
	if (!n) return 1;

	int x = power(a, n / 2);
	if (n & 1) return x * x * a;
	return x * x;
}

int main() {

	cout << power(4, 3) << endl;

	return 0;
}
















