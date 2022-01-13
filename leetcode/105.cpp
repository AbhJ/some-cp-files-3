/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	map<int, int> pos;
	TreeNode *dfs (int l, int r, int &cnt, vector<int> &preorder) {
		if (l > r)
			return NULL;
		TreeNode *ret = new TreeNode (preorder[cnt]);
		int tmp = cnt++;
		ret -> left = dfs (l, pos[preorder[tmp]] - 1, cnt, preorder);
		ret -> right = dfs (pos[preorder[tmp]] + 1, r, cnt, preorder);
		return ret;
	}
	TreeNode *buildTree (vector<int> &preorder, vector<int> &inorder) {
		int n = preorder.size(), cnt = 0;
		for (int i = 0; i < inorder.size(); i++)
			pos[inorder[i]] = i;
		return dfs (0, n - 1, cnt, preorder);
	}
};
