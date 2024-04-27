#include <iostream>
using namespace std;

class segmentTree {
public:
	int *tree;
	int n;

	segmentTree(int N) {
		n = N;
		tree = new int[3 * N];
	}

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
	t.updatePoint(0, n - 1, 1, -10);
	// t.printTree();

	cout << t.query(a, 0, n - 1, 0, 1) << endl;


	return 0;
}
















