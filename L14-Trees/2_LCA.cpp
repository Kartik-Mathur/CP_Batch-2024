#include <iostream>
#include<vector>
using namespace std;

class node {
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

node* createTree() {
	node* root = NULL;
	int data;
	cin >> data;
	if (data == -1) return root;

	root = new node(data);
	// create LST
	root->left = createTree();

	// create RST
	root->right = createTree();

	return root;
}

void preOrder(node* root) {
	// base case
	if (!root) return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root) {
	// base case
	if (!root) return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(node* root) {
	// base case
	if (!root) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}


bool findRoute(node* root, int d, vector<int> &x) {
	if (!root) return false;

	x.push_back(root->data);
	if (root->data == d) return true;

	bool leftSeBaatBani = findRoute(root->left, d, x);
	if (leftSeBaatBani) return true;

	bool rightSeBaatBani = findRoute(root->right, d, x);
	if (rightSeBaatBani) return true;

	x.pop_back(); // backtracking
	return false;
}




// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = createTree();

	// preOrder(root);
	// cout << endl;
	// inOrder(root);
	// cout << endl;
	// postOrder(root);
	// cout << endl;
	vector<int> x, y;
	findRoute(root, 4, x);
	findRoute(root, 1, y);
	for (auto e : x) cout << e << " ";
	cout << endl;

	for (auto e : y) cout << e << " ";
	cout << endl;


	return 0;
}
















