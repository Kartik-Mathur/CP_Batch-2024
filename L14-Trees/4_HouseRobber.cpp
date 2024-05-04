#define node TreeNode
class Pair {
public:
	int choriKariRoot = 0;
	int choritNahiKariRoot = 0;
};

class Solution {
public:

	Pair solve(node* root) {
		if (!root) return {0, 0};

		Pair left = solve(root->left);
		Pair right = solve(root->right);

		Pair p;
		p.choriKariRoot = root->val + left.choritNahiKariRoot + right.choritNahiKariRoot;
		p.choritNahiKariRoot = max(left.choritNahiKariRoot, left.choriKariRoot)
		                       + max(right.choriKariRoot, right.choritNahiKariRoot);
		return p;
	}

	int rob(TreeNode* root) {
		Pair ans = solve(root);
		return max(ans.choriKariRoot, ans.choritNahiKariRoot);
	}
};
















