#include <bits/stdc++.h>
using namespace std;
int dp[3005][3005] = {0};

void printLCSOne(const string &s1, const string &s2, int m, int n) {
	string x = "";
	while (m and n) {
		if (s1[m - 1] == s2[n - 1]) {
			x.push_back(s1[m - 1]);
			m--;
			n--;
		}
		else {
			if (dp[m][n] == dp[m - 1][n]) m--;
			else n--;
		}
	}

	reverse(x.begin(), x.end());
	cout << x << endl;
}

void bottomUp(const string &s1, const string &s2) {
	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	printLCSOne(s1, s2, s1.size(), s2.size());
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s1;
	string s2;
	cin >> s1 >> s2;
	bottomUp(s1, s2);

	return 0;
}
















