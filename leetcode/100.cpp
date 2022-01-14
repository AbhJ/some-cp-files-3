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
	bool isSameTree (TreeNode *A, TreeNode *B) {
		if (A == NULL and B == NULL)
			return 1;
		if (A == NULL or B == NULL)
			return 0;
		return (A->val == B->val) and isSameTree (A->left, B->left) and isSameTree (A->right, B->right);;
	}
};
