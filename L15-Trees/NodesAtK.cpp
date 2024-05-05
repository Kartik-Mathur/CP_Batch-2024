#define node TreeNode
class Solution {
public:
	vector<int> ans;
	void nodesAtKSubtree(node* root, int k, int d = 0) {
		if (!root) return;

		if (d == k) {
			ans.push_back(root->val);
			return;
		}

		nodesAtKSubtree(root->left, k, d + 1);
		nodesAtKSubtree(root->right, k, d + 1);
	}

	int solve(node* root, node* target, int k) {
		if (!root) return -1;

		if (root == target) {
			return 0;
		}
		// ask the LST to give the distance from its root to target
		int d = solve(root->left, target, k);
		if (d != -1) { // Matlab target is present in LST
			if (d + 1 == k) {
				// if d+1 == k that means root is the answer
				ans.push_back(root->val);
				// ab iske upar nodes at distance k possible nhi h
				return -1;
			}

			int x = k - (d + 2);
			nodesAtKSubtree(root->right, x);
			return d + 1;
		}

		d = solve(root->right, target, k);
		if (d != -1) { // Matlab target is present in RST
			if (d + 1 == k) {
				ans.push_back(root->val);
				return -1;
			}
			int x = k - (d + 2);
			nodesAtKSubtree(root->left, x);
			return d + 1;
		}
		// Na LST se ans aaya na RST se aaya thus return -1
		return -1;
	}

	vector<int> distanceK(TreeNode* root,
	                      TreeNode* target, int k) {

		nodesAtKSubtree(target, k);

		solve(root, target, k);
		return ans;
	}
};
























