#include <iostream>
#include <algorithm>
using namespace std;
#define w(t) int t; cin>>t; while(t--)
#define F(a,n) for (int i = 0; i < n; ++i) cin >> a[i];

int a[100005];
int cows;
int n;

bool cowsPlaceHui(int dist) {
	int cowsPlaced = 1;
	int pd = a[0];

	for (int i = 1; i < n; ++i)
	{
		if (a[i] - pd >= dist) {
			cowsPlaced++;
			pd = a[i];
		}

		if (cowsPlaced == cows) return true;
	}

	return false;
}

int aggressiveCows() {
	int s = 0, e = a[n - 1] - a[0];
	int ans;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (cowsPlaceHui(mid)) ans = mid, s = mid + 1;
		else  e = mid - 1;
	}
	return ans;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	w(t) {
		cin >> n >> cows;
		F(a, n);

		sort(a, a + n);
		cout << aggressiveCows() << endl;
	}



	return 0;
}
















