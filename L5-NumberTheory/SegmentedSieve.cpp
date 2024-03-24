#include <bits/stdc++.h>
using namespace std;
#define w(t) int t;cin>>t;while(t--)
#define int long long

bitset<1000005> bs;
vector<int> primes;
int n, m;

void sieve() {
	int n = 1000000;
	bs.set();
	bs[0] = bs[1] = 0;

	for (int i = 2; i * i <= n; ++i)
	{
		if (bs[i] == 1) {
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i)
			{
				bs[j] = 0;
			}
		}
	}

}

void segmentedSieve() {
	bs.set();

	int i = 0;
	while (primes[i]*primes[i] <= n) {

		int start = (m / primes[i]) * primes[i];

		if (primes[i] >= m)
			start = 2 * primes[i];

		while (start < m) start += primes[i];

		for (int j = start; j <= n; j += primes[i])
		{
			bs[j - m] = 0;
		}
		i++;
	}

	for (int i = m; i <= n; ++i)
	{
		if (bs[i - m] == 1 and i >= 2) cout << i << endl;
	}
	cout << endl;

}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	sieve();

	w(t) {
		cin >> m >> n;
		segmentedSieve();
	}
	return 0;
}
















