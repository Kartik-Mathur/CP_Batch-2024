#include <bits/stdc++.h>
using namespace std;

void printLCSOne(const string &s1, const string &s2, int dp[][3001],
                 int m, int n, string &x) {
	// base case
	if (m == 0 and n == 0) {
		if (x.size() > 0) {
			reverse(x.begin(), x.end());
		}
		cout << x << endl;
		return;
	}

	// recursive case
	if (s1[m - 1] == s2[n - 1]) {
		x.push_back(s1[m - 1]);
		printLCSOne(s1, s2, dp, m - 1, n - 1, x);
		x.pop_back();
	}
	else {
		if (dp[m - 1][n] == dp[m][n]) printLCSOne(s1, s2, dp, m - 1, n, x);
		else if (dp[m][n - 1] == dp[m][n]) printLCSOne(s1, s2, dp, m, n - 1, x);
	}
}

int dp[3001][3001] = {0};
int bottomUp(const string &s1, const string &s2) {
	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string x = "";
	printLCSOne(s1, s2, dp, s1.size(), s2.size(), x);
	return dp[s1.size()][s2.size()];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s1;
	string s2;
	cin >> s1 >> s2;
	int x = bottomUp(s1, s2);

	return 0;
}
















