#define node TreeNode
class Solution {
public:

	vector<int> levelOrder(node* root) {
		queue<node*> q;

		q.push(root);
		q.push(NULL);
		vector<int> ans;
		while (!q.empty()) {

			node* x = q.front();
			q.pop();
			int lastData;
			if (x) {
				lastData = x->val;
				if (x->left) q.push(x->left);
				if (x->right) q.push(x->right);
			}
			else {
				ans.push_back(lastData);
				if (!q.empty()) q.push(NULL);
			}
		}
		return ans;
	}

	vector<int> rightSideView(node* root) {
		return levelOrder(root);
	}
};