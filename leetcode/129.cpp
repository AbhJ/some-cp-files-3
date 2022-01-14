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
	void dfs (TreeNode *A, int &sum, int curSum) {
		if (A == NULL)
			return;
		curSum = curSum * 10 + A -> val;
		dfs (A -> left, sum, curSum);
		dfs (A -> right, sum, curSum);
		if (A -> left == NULL and A -> right == NULL)
			sum += curSum;
	}
	int sumNumbers (TreeNode *root) {
		int sum = 0;
		dfs (root, sum, 0);
		return sum;
	}
};
