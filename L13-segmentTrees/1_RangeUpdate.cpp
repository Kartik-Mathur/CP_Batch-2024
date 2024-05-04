#include <iostream>
using namespace std;

class segmentTree {
public:
	int *tree;
	int n;
	int *lazy;

	segmentTree(int N): n(N), tree(new int[3 * N] {0}), lazy(new int[3 * N] {0}) {}

	void buildTree(int *arr, int s, int e, int indx = 1) {
		// base case
		if (s == e) {
			tree[indx] = arr[s];
			return;
		}
		if (s > e) return;

		// recursive case
		int mid = (s + e) / 2;
		buildTree(arr, s, mid, 2 * indx);
		buildTree(arr, mid + 1, e, 2 * indx + 1);
		tree[indx] = min(tree[2 * indx], tree[2 * indx + 1]);
	}

	int query(int *arr, int s, int e, int l, int r, int indx = 1) {
		// 1. no overlap
		if (s > r || e < l) return INT_MAX;

		// 2. complete overlap
		if (s >= l and e <= r) return tree[indx];

		// 3. parial overlap
		int mid = (s + e) / 2;
		int left = query(arr, s, mid, l, r, 2 * indx);
		int right = query(arr, mid + 1, e, l, r, 2 * indx + 1);
		return min(left, right);
	}


	void updatePoint(int s, int e, int i, int val, int indx = 1) {
		if (s > i || e < i) return;

		if (s == e) {
			tree[indx] += val;
			return;
		}
		int mid = (s + e) / 2;
		updatePoint(s, mid, i, val, 2 * indx);
		updatePoint(mid + 1, e, i, val, 2 * indx + 1);
		tree[indx] = min(tree[2 * indx], tree[2 * indx + 1]);
	}

	void updateRange(int s, int e, int l, int r, int val, int indx = 1) {
		// 1. No overlap
		if (l > e || r < s) return;

		// 2. Complete overlap
		if (s == e) {
			tree[indx] += val;
			return;
		}

		// 3. Partial Overlap
		int mid = (s + e) / 2;
		updateRange(s, mid, l, r, val, 2 * indx);
		updateRange(mid + 1, e, l, r, val, 2 * indx + 1);
		tree[indx] = min(tree[2 * indx], tree[2 * indx + 1]);
	}

	void updateRangeLazy(int s, int e, int l, int r, int val, int indx = 1) {
		// Agar current indx par lazy value present hai toh usse resolve kro
		if (lazy[indx] != 0) {
			// Us lazy value ko apne indx par add karo
			tree[indx] += lazy[indx];
			if (s != e) {
				// agar bache exist krte hai
				// toh lazy value bacho par pass kardo
				lazy[2 * indx] += lazy[indx];
				lazy[2 * indx + 1] += lazy[indx];
			}
			// apni lazy value hum add kar chuke hai toh usse 0 kardo
			lazy[indx] = 0;
		}
		// 1. No overlap
		if (l > e || r < s) return;

		// 2. Complete overlap
		if (s >= l and e <= r) {
			tree[indx] += val;
			if (s != e) {
				lazy[2 * indx] += val;
				lazy[2 * indx + 1] += val;
			}
			return;
		}

		// 3. Partial overlap
		int mid = (s + e) / 2;
		updateRangeLazy(s, mid, l, r, val, 2 * indx);
		updateRangeLazy(mid + 1, e, l, r, val, 2 * indx + 1);
		tree[indx] = min(tree[2 * indx], tree[2 * indx + 1]);
	}

	int queryRangeLazy(int s, int e, int l, int r, int indx = 1) {
		// Agar current indx par lazy value present hai toh usse resolve kro
		if (lazy[indx] != 0) {
			// Us lazy value ko apne indx par add karo
			tree[indx] += lazy[indx];
			if (s != e) {
				// agar bache exist krte hai
				// toh lazy value bacho par pass kardo
				lazy[2 * indx] += lazy[indx];
				lazy[2 * indx + 1] += lazy[indx];
			}
			// apni lazy value hum add kar chuke hai toh usse 0 kardo
			lazy[indx] = 0;
		}

		// 1. No overlap
		if (l > e || r < s) return INT_MAX;

		// 2. Complete overlap
		if (s >= l and e <= r) {
			return tree[indx];
		}

		// 3. Partial
		int mid = (s + e) / 2;
		int left = queryRangeLazy(s, mid, l, r, 2 * indx);
		int right = queryRangeLazy(mid + 1, e, l, r, 2 * indx + 1);
		return min(left, right);
	}

	void printTree() {
		for (int i = 1; i < 3 * n; ++i)
		{
			cout << tree[i] << " ";
		}
		cout << endl;
	}
};

int main() {

	int a[] = {1, 2, -5, 3, 6, -1};
	int n = sizeof(a) / sizeof(int);

	segmentTree t(n);

	t.buildTree(a, 0, n - 1);
	// t.updatePoint(0, n - 1, 1, -10);
	// t.printTree();
	t.updateRangeLazy(0, n - 1, 0, 5, 10);
	t.updateRangeLazy(0, n - 1, 0, 2, 10);
	t.updateRangeLazy(0, n - 1, 2, 2, 10);

	cout << t.queryRangeLazy(0, n - 1, 0, 5) << endl;


	return 0;
}
















