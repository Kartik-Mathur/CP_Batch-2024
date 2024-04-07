#include <iostream>
using namespace std;
#define int long long
int p = 1e9 + 7;

int stringToInt(const string &a, int p) {
	int ans = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		ans = ans * 10 + (a[i] - '0');
		ans %= p;
	}
	return ans % p;
}

int power(int a, int n) {
	if (!n) return 1;

	int x = power(a, n / 2);
	if (n & 1) return (((x % p) * (x % p) % p) * (a % p) % p) % p;
	return ((x % p) * (x % p) % p);
}

int32_t main() {

	string a, b;
	cin >> a >> b;

	//FIND THIS:  (a ^ b) % p;
	// Purpose is to bring a and b after mod with p within integer range
	// a%p < p and b%(p-1) < p-1
	int x = stringToInt(a, p);
	int y = stringToInt(b, p - 1);

	cout << power(x, y) << endl;



	return 0;
}
















