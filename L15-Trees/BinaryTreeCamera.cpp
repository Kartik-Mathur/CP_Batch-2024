#define node TreeNode
class Solution {
public:
	unordered_map<node*, bool> vigilance;
	int camera = 0;
	void solve(node* root, node* parent) {
		if (!root) return;

		solve(root->left, root);
		solve(root->right, root);

		if ((parent == NULL and vigilance[root] == false) or
		        (vigilance[root->left] == false) or
		        vigilance[root->right] == false) {
			camera++;
			vigilance[root] = true;
			vigilance[parent] = true;
			vigilance[root->left] = true;
			vigilance[root->right] = true;

		}
	}

	int minCameraCover(TreeNode* root) {
		vigilance[NULL] = true;
		solve(root, NULL);
		return camera;
	}
};












