// https://www.spoj.com/problems/SPP/
#include <iostream>
#include <vector>
using namespace std;

int p;
int k;
int n, m;

vector<int> c, b, F1;
vector<int> ps;

vector<vector<int > > multiplyMatrix(vector< vector<int> > A,
                                     vector< vector<int> > B) {
	vector< vector<int> > ans(k + 2, vector<int>(k + 2, 0));
	for (int i = 1; i <= k + 1; ++i)
	{
		for (int j = 1; j <= k + 1; ++j)
		{
			for (int m = 1; m <= k + 1; ++m)
			{
				ans[i][j] = (ans[i][j]  + (A[i][m] % p) * (B[m][j]) % p) % p;
			}
		}
	}
	return ans;
}

vector<vector<int> > power(vector< vector<int> > &T, int n) {
	if (n == 1) {
		return T;
	}

	if (n & 1) return multiplyMatrix(power(T, n - 1), T);
	vector<vector<int> >X = power(T, n / 2);
	return multiplyMatrix(X, X);
}


int solve(int n) {
	if (n <= k) {
		return ps[n - 1];
	}

	vector< vector<int> > T(k + 2, vector<int>(k + 2, 0));
	T[1][1] = 1;
	// Create the first two rows
	for (int i = 2; i <= k + 1; ++i)
	{
		T[1][i] = T[2][i] = c[i - 2];
	}

	int i = 3, j = 2;
	while (i <= k + 1) T[i++][j++] = 1;

	// 2. Find vector F1
	F1.resize(k + 2);
	F1[1] = ps[k - 1];
	j = k - 1;
	for (int i = 2; i <= k + 1; ++i)
	{
		F1[i] = b[j--];
	}

	// 3. Find T^(n-1)
	T = power(T, n - k);

	// 4. Find answer
	int ans = 0;
	for (int i = 1; i <= k + 1; ++i)
	{
		ans += (T[1][i] % p * F1[i] % p) % p;
	}
	return ans;
}

int main() {
	int t; cin >> t; while (t--) {
		cin >> k;
		for (int i = 0; i < k; ++i)
		{
			int x; cin >> x;
			b.push_back(x);
		}
		// Creating the prefix sum array using b[i]
		ps.resize(k);
		ps[0] = b[0];
		for (int i = 1; i < k; ++i)
		{
			ps[i] = ps[i - 1] + b[i];
		}

		for (int i = 0; i < k; ++i)
		{
			int x; cin >> x;
			c.push_back(x);
		}
		cin >> m >> n >> p;

		cout << (solve(n) % p - solve(m - 1) % p) % p << endl;
	}


	return 0;
}
















