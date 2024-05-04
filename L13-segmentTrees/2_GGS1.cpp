#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int ts; // totalSum
	int ps; // prefixSum
	int ss; // suffixSum
	int ms; // maxSum
};

class segmentTree {
public:
	node* tree;
	int n;
	segmentTree(int n) {
		this-> n = n;
		tree = new node[4 * n];
	}

	void buildTree(int *arr, int s, int e, int indx = 1) {
		if (s > e) return;
		if (s == e) {
			tree[indx] = {arr[s], arr[s], arr[s], arr[s]};
			return;
		}

		int mid = (s + e) / 2;
		buildTree(arr, s, mid, 2 * indx);
		buildTree(arr, mid + 1, e, 2 * indx + 1);

		node left = tree[2 * indx];
		node right = tree[2 * indx + 1];

		tree[indx].ps = max(left.ps, left.ts + right.ps);
		tree[indx].ss = max(right.ss, right.ts + left.ss);
		tree[indx].ts = left.ts + right.ts;
		tree[indx].ms = max(left.ms, max(right.ms, left.ss + right.ps));
	}

	node query(int s, int e, int l, int r, int indx = 1) {
		if (s > r || e < l) return {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
		if (s >= l and e <= r) return tree[indx];
		int mid = (s + e) / 2;

		node left = query(s, mid, l, r, 2 * indx);
		node right = query(mid + 1, e, l, r, 2 * indx + 1);

		node temp;

		temp.ps = max(left.ps, left.ts + right.ps);
		temp.ss = max(right.ss, right.ts + left.ss);
		temp.ts = left.ts + right.ts;
		temp.ms = max(left.ms, max(right.ms, left.ss + right.ps));
		return temp;
	}
};

int main() {

	int n; cin >> n;
	int a[100000];
	for (int i = 0; i < n; ++i) cin >> a[i];
	segmentTree t(n);

	t.buildTree(a, 0, n - 1);

	int q; cin >>  q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << t.query(0, n - 1, l - 1, r - 1).ms << endl;
	}


	return 0;
}
















