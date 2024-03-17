#include <iostream>
using namespace std;
int n, m;
int books[100005], max_pages = 0, pages_sum = 0;

bool kyaPagesReadHoPaaye(int p) {
	int cs = 1;
	int cp = 0;
	for (int i = 0; i < n; ++i)
	{
		if (cp + books[i] <= p) {
			cp += books[i];
		}
		else {
			cs++;
			cp = books[i];
			if (cs > m) return false;
		}
	}

	return true;
}

int solve() {
	int s = max_pages, e = pages_sum;
	int ans = 0;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (kyaPagesReadHoPaaye(mid)) {
			ans = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}

	return ans;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> books[i],
			    max_pages = max(max_pages, books[i]),
			    pages_sum += books[i];

		cout << solve() << endl;
	}

	return 0;
}
















