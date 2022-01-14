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
	int dfs (TreeNode *A) {
		if (A == NULL)
			return 0;
		int h1 = 0, h2 = 0;
		if (A->left != NULL)
			h1 = dfs (A->left);
		if (A->right != NULL)
			h2 = dfs (A->right);
		if (h1 == - 1 or h2 == - 1)
			return - 1;
		if (abs (h1 - h2) < 2)
			return 1 + max (h1, h2);
		return - 1;
	}
	bool isBalanced (TreeNode *root) {
		return !! (~dfs (root));
	}
};
