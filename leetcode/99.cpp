class Solution {
public:
	TreeNode *isProblematic1 = new TreeNode (- 1), *isProblematic2 = new TreeNode (- 1), *last = new TreeNode (- 1);
	void helper (TreeNode *root) {
		if (root == NULL)
			return;
		helper (root -> left);
		if (isProblematic1 -> val == - 1 and root -> val < last -> val)
			isProblematic1 = last;
		if (isProblematic1 -> val != - 1 and root -> val < last -> val)
			isProblematic2 = root;
		last = root;
		helper (root -> right);
	}
	void recoverTree (TreeNode *root) {
		helper (root);
		swap (isProblematic1 -> val, isProblematic2 -> val);
	}
};

