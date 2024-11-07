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

	long long lastSeen = - (1LL << 31) - 1;
	bool possible = true;

	bool isValidBST (TreeNode* root) {
		possible = true;
		inorder (root);
		return possible;
	}

	void inorder (TreeNode* root) {
		if (root == NULL)
			return;
		inorder (root -> left);
		if (lastSeen >= root -> val) {
			possible = false;
		}
		lastSeen = root -> val;
		inorder (root -> right);
	}
};