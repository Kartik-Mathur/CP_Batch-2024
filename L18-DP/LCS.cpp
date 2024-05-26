#include <iostream>
using namespace std;

int lcs(string &s1, string &s2, int i, int j) {
	// base case
	if ( i == 0 || j == 0) return 0;
	// recursive case
	if (s1[i - 1] == s2[j - 1]) return 1 + lcs(s1, s2, i - 1, j - 1);
	return max(lcs(s1, s2, i, j - 1), lcs(s1, s2, i - 1, j));
}

int topDown(string &s1, string &s2, int i, int j, int dp[][100]) {
	// base case
	if ( i == 0 || j == 0) return dp[i][j] = 0;

	if (dp[i][j] != -1) return dp[i][j];
	// recursive case
	if (s1[i - 1] == s2[j - 1])
		return dp[i][j] = 1 + topDown(s1, s2, i - 1, j - 1, dp);

	return dp[i][j] = max (topDown(s1, s2, i, j - 1, dp),
	                       topDown(s1, s2, i - 1, j, dp));
}

void printLCS(const string &s1, const string &s2, int dp[][1000],
              int m, int n, string &x) {
	// base case
	if (m == 0 and n == 0) {
		reverse(x.begin(), x.end());
		cout << x << endl;
		return;
	}

	// recursive case
	if (s1[m - 1] == s2[n - 1]) {
		x.push_back(s1[m - 1]);
		printLCS(s1, s2, dp, m - 1, n - 1, x);
		x.pop_back();
	}
	else {
		if (dp[m - 1][n] == dp[m][n]) printLCS(s1, s2, dp, m - 1, n, x);
		if (dp[m][n - 1] == dp[m][n]) printLCS(s1, s2, dp, m, n - 1, x);
	}
}

void printLCSOne(const string &s1, const string &s2, int dp[][3001],
                 int m, int n, string &x) {
	// base case
	if (m == 0 and n == 0) {
		reverse(x.begin(), x.end());
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
	// int dp[100][100];
	// memset(dp, -1, sizeof dp);
	// cout << topDown(s1, s2, s1.size(), s2.size(), dp) << endl;
	bottomUp(s1, s2);
	// cout << bottomUp(s1, s2) << endl;



	return 0;
}
















