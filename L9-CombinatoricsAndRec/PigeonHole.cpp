#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	int ps[1000];
	int freq[1000] = {0};
	ps[0] = a[0] % n;
	for (int i = 1; i < n; ++i)
	{
		ps[i] += ps[i - 1] + a[i];
		ps[i] %= n;
		freq[ps[i]]++;
	}


	freq[0]++; // To cater empty
	// subarray
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += (freq[i] * (freq[i] - 1)) / 2;
	}
	cout << ans << endl;




	return 0;
}
















