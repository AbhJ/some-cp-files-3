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

void dfs (TreeNode *A, vector<int> &v) {
	if (A == NULL)
		return;
	dfs (A -> left, v);
	v.emplace_back (A -> val);
	dfs (A -> right, v);
}

class Solution {
public:
	vector<int> inorderTraversal (TreeNode *root) {
		vector<int> v;
		dfs (root, v);
		return v;
	}
};
