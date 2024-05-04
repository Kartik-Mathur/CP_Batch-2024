#define node TreeNode
class Solution {
public:
	unordered_map < int, int> h;
	void rightView(node* root, int d, int &minD, int &maxD) {
		if (!root) return;

		// Root ka kaam
		if (h.count(d) == 0) {
			minD = min(minD, d);
			maxD = max(maxD, d);
			h[d] = root->val;
		}

		rightView(root->right, d + 1, minD, maxD);
		rightView(root->left, d + 1, minD, maxD);
	}

	vector<int> rightSideView(node* root) {
		int minD = INT_MAX;
		int maxD = INT_MIN;
		rightView(root, 0, minD, maxD);

		vector<int> ans;
		for (int i = minD; i <= maxD; ++i)
		{
			ans.push_back(h[i]);
		}
		return ans;
	}
};















