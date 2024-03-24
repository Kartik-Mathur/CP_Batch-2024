#include <iostream>
using namespace std;



void factorial(int Number) {
	int a[1000000] = {0};
	int n = 1;
	a[0] = 1;
	int i;
	for (int no = 2; no <= Number; ++no)
	{
		int carry = 0;
		for (i = 0; i < n; ++i)
		{
			int x = a[i] * no + carry;
			a[i] = x % 10;
			carry = x / 10;
		}

		while (carry) {
			a[i] = carry % 10;
			carry /= 10;
			i++;
		}
		n = i;
	}

	for (int i = n - 1; i >= 0; --i)
	{
		cout << a[i];
	}
	cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	factorial(n);


	return 0;
}
















