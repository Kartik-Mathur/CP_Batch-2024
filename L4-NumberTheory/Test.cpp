#include <iostream>
using namespace std;

int main() {

	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	int bits = sizeof(primes) / sizeof(int);
	int ans, n = 1000, sum = 0;
	for (int i = 1; i < (1 << bits); ++i)
	{
		ans = 1;
		int bitsCount = __builtin_popcount(i);
		for (int j = 0; j < bits; ++j)
		{
			if (i & (1 << j)) {
				// cout << 1 << " ";
				ans *= primes[j];
			}
			// else cout << 0 << " ";
		}
		if (bitsCount & 1) sum += n / ans;
		else sum -= n / ans;
	}
	cout << "Numbers: " << sum << endl;

	return 0;
}
















