#include <bits/stdc++.h>
using namespace std;
#define w(t) int t;cin>>t;while(t--)
#define int long long

bitset<1000000> bs;
vector<int> primes;
int n, m;

void sieve() {
	int n = 1000000;
	bs.set();
	bs[0] = bs[1] = 0;

	for (int i = 2; i * i <= n; ++i)
	{
		if (bs[i] == 1) {
			// primes.push_back(i);
			for (int j = i * i; j <= n; j += i)
			{
				bs[j] = 0;
			}
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if (bs[i] == 1) primes.push_back(i);
	}

}

void primeFactorsOptimised(int n) {
	for (int i = 0; i < primes.size() and primes[i] <= n ; ++i)
	{
		int cnt = 0, no = primes[i];

		while (n % no == 0) {
			cnt++;
			n /= no;
		}
		if (cnt > 0) {
			cout << no << "^" << cnt << " ";
		}
	}
	cout << endl;

}

int countDivisors(int n) {
	int ans = 1;
	for (int i = 0; i < primes.size() and primes[i] <= n ; ++i)
	{
		int cnt = 0, no = primes[i];

		while (n % no == 0) {
			cnt++;
			n /= no;
		}
		ans = ans * (cnt + 1);
	}
	return ans;
}

void primeFactorisation(int n) {

	int no = 2;
	while (n > 1) {
		int cnt = 0;
		while (n % no == 0) {
			cnt++;
			n /= no;
		}
		if (cnt > 0) {
			cout << no << "^" << cnt << " ";
		}
		no++;
	}
	cout << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	sieve();

	int n;
	cin >> n;

	primeFactorisation(n);

	primeFactorsOptimised(n);

	return 0;
}












