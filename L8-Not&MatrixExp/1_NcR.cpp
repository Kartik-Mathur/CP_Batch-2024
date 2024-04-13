#include <iostream>
using namespace std;
#define ll long long

ll p = 1e9 + 7;
int fact[1000005];

ll modMul(ll a, ll b) {
	return ( (a % p) * (b % p) + p) % p;
}

ll factPower(ll a, ll n) {
	if (n == 0) return 1;
	ll ca = factPower(a, n / 2);
	if (n & 1) {
		return modMul(ca, modMul(ca, a));
	}
	return modMul(ca, ca);
}

ll inverse(ll a) {
	return factPower(a, p - 2);
}

ll ncr(ll n, ll r) {
	return modMul(modMul(fact[n], inverse(fact[r])) , inverse(fact[n - r]));
}


int main() {
	ll n = 1000000;
	ll r = 100000;
	fact[0] = 1;
	for (ll i = 1; i <= n; ++i)
	{
		fact[i] = modMul(fact[i - 1] , i);
	}

	cout << ncr(n, r) << endl;

	return 0;
}
















