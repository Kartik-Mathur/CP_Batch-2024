#define node TreeNode
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;


		node* left = lowestCommonAncestor(root->left, p, q);
		node* right = lowestCommonAncestor(root->right, p, q);

		if (left and right) return root;
		if (left) return left;
		return right;
	}
};