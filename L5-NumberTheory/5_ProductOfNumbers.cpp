#include <iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t; while (t--) {
		int n;
		cin >> n;
		int factor1 = -1, factor2 = -1;
		for (int i = 2; i * i < n; ++i)
		{
			if (n % i == 0) {
				if (factor1 == -1) {
					factor1 = i;
					n /= factor1;
				}
				else if (factor2 == -1) {
					factor2 = i;
					n /= factor2;
				}
			}

			if (factor2 != -1) break;
		}

		if (factor2 != -1) {
			cout << "YES\n";
			cout << factor1 << " " << factor2 << " " << n << endl;
		}
		else cout << "NO\n";
	}

	return 0;
}
















