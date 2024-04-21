#include <iostream>
using namespace std;

int main() {

	vector<int> whites, blacks;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		whites.push_back(x);
	}

	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		blacks.push_back(x);
	}

	sort(whites.begin(), whites.end());
	sort(blacks.begin(), blacks.end());

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += abs(whites[i] - blacks[i]);
	}
	cout << ans << endl;

	return 0;
}
















