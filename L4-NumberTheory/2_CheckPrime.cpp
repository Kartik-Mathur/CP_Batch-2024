#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int n = 19, i;

	for (i = 2; i * i <= n; ++i)
	{
		if (n % i == 0) break;
	}
	if (i * i <= n) cout << "Not Prime\n";
	else cout << "Prime\n";

	return 0;
}
















