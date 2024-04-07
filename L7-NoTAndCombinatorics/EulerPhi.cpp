#include <iostream>
#include <vector>
using namespace std;

vector<int> pF; // To store primeFactors

void findPower(int n) {
	for (int i = 2; i <= n; ++i)
	{
		int p = 0;
		while (n % i == 0) {
			p++;
			n /= i;
		}
		if (p)
			cout << i << "^" << p << endl;
	}
}

void findPower1(int n) {
	for (int i = 2; i * i <= n; ++i)
	{
		int p = 0;
		while (n % i == 0) {
			p++;
			n /= i;
		}
		if (p) {
			// cout << i << "^" << p << endl;
			pF.push_back(i);
		}
	}

	if (n > 1) {
		// cout << n << "^" << 1 << endl;
		pF.push_back(n);
	}
}

int eulerPhi(int n) {
	findPower1(n);
	int ans = n;
	for (int i = 0; i < pF.size(); ++i)
	{
		ans = (ans * pF[i] - ans) / pF[i];
	}
	return ans;
}


int main()s {

	// findPower1(74);
	cout << eulerPhi(8) << endl;
	return 0;
}
















