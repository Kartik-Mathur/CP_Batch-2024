#include <iostream>
#include <vector>
using namespace std;

int p = 1e9 + 7;
int k;
int n;
vector<int> c, initVal, F1;

vector<vector<int > > multiplyMatrix(vector< vector<int> > A,
                                     vector< vector<int> > B) {
	vector< vector<int> > ans(k + 1, vector<int>(k + 1, 0));
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			for (int m = 1; m <= k; ++m)
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


int nthFibo(int n) {
	if (n <= k)
		return initVal[n];
	// 1. Transformation Matrix
	// Create the transformation matrix
	vector< vector<int> > T(k + 1, vector<int>(k + 1, 0));
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (i < k) {
				if (i + 1 == j) T[i][j] = 1;
				else T[i][j] = 0;
			}
			else {
				T[i][j] = c[k - j];
			}
		}
	}

	// 2. Find vector F1
	F1.resize(k + 1);
	for (int i = 1; i <= k; ++i)
	{
		F1[i] = initVal[i - 1];
	}

	// 3. Find T^(n-1)
	T = power(T, n - 1);

	// 4. Find answer
	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += (T[i][1] % p * F1[i] % p) % p;
	}
	return ans;
}

int main() {
	// f(i) = 1*f(i-1) + 1*f(i-2);
	// 2 1 1 0 1 5
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int x; cin >> x;
		c.push_back(x);
	}

	for (int i = 0; i < k; ++i)
	{
		int x; cin >> x;
		initVal.push_back(x);
	}
	cin >> n;

	cout << nthFibo(n) << endl;


	return 0;
}
















