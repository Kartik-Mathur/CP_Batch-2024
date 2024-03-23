#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bitset<100000005> bs;
vector<int> primes;

void sieve(int n) {
	bs.set(); // set all the bits to 1
	bs[0] = bs[1] = 0; // Not a prime number

	for (int i = 2; i <= n; ++i)
	{
		if (bs[i] == 1) {
			primes.push_back(i);
			for (int j = 2 * i; j <= n; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}

void sieveOptimized(int n) {
	bs.set(); // set all the bits to 1
	bs[0] = bs[1] = 0; // Not a prime number

	for (int i = 2; i * i <= n; ++i)
	{
		if (bs[i] == 1) {
			primes.push_back(i);
			for (int j = 2 * i; j <= n; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}

void sieveOptimized2(int n) {
	bs.set(); // set all the bits to 1
	bs[0] = bs[1] = 0; // Not a prime number

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

bool checkPrime(int n) {
	int i = 0;
	while (primes[i]*primes[i] <= n)
	{
		if (n % primes[i] == 0) return false;
		i++;
	}
	return true;
}

int main() {
	int n = 113;

	sieveOptimized2(10000005);

	if (checkPrime(n)) cout << "Prime\n";
	else cout << "Not Prime\n";

	// for (auto v : primes) {
	// 	cout << v << " ";
	// }
	// cout << endl;
	// for (int i = 2; i <= n; ++i)
	// {
	// 	if (bs[i]) cout << i << " ";
	// }
	// cout << endl;



	return 0;
}
















