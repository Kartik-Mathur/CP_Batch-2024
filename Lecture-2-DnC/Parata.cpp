#include <iostream>
#include <algorithm>
using namespace std;
#define w(t) int t; cin>>t; while(t--)
#define F(a,n) for (int i = 0; i < n; ++i) cin >> a[i];

int n;
int parathas;
int cook_rank[50];

bool kyaParantheBannPaye(int t) {
	int total_KitneBane = 0;

	for (int i = 0; i < n; ++i)
	{
		int current_Rank = cook_rank[i];
		int current_CookTime = 0;

		int parantha_No = 1;
		while (current_CookTime + parantha_No * current_Rank <= t) {
			total_KitneBane++;
			current_CookTime += parantha_No * current_Rank;
			parantha_No++;
		}
	}

	if (total_KitneBane >= parathas) return true;
	return false;
}

int solve() {
	int s = 0, e = 1e9;
	int ans;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (kyaParantheBannPaye(mid)) ans = mid, e = mid - 1;
		else s = mid + 1;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	w(t) {
		cin >> parathas >> n;
		F(cook_rank, n);

		cout << solve() << endl;
	}


	return 0;
}
















