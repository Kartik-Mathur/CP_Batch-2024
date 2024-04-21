#include <iostream>
using namespace std;

int crossInversions(int *a, int s,
                    int e) {
	int m = (s + e) / 2;
	int i = s, j = m + 1, k = s;
	int temp[1000];
	int ans = 0;

	while (i <= m and j <= e) {
		if (a[i] > a[j]) {
			ans += m - i + 1;
			temp[k++] = a[j++];
		}
		else {
			temp[k++] = a[i++];
		}
	}

	while (i <= m) temp[k++] = a[i++];
	while (j <= e) temp[k++] = a[j++];

	for (int i = s; i <= e; ++i)
	{
		a[i] = temp[i];
	}
	return ans;
}


int inversionCount(int *a, int s, int e) {
	// base case
	if (s >= e) return 0;

	// recursion case
	int ans = 0;
	int m = (s + e) / 2;

	int op1 = inversionCount(a, s, m);
	int op2 = inversionCount(a, m + 1, e);
	int op3 = crossInversions(a, s, e);
	ans = op1 + op2 + op3;
	return ans;

}

int main() {

	int a[] = {1, 5, 2, 6, 3, 0};
	int n = sizeof(a) / sizeof(int);

	cout << inversionCount(a, 0, n - 1) << endl;


	return 0;
}
















