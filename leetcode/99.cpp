class Solution {
public:
	TreeNode *isProblematic1 = new TreeNode (- 10), *isProblematic2 = new TreeNode (- 10), *last = new TreeNode (- 10);
	void helper (TreeNode *root) {
		if (root == NULL)
			return;
		helper (root -> left);
		if (isProblematic1 -> val == - 10 and root -> val < last -> val)
			isProblematic1 = last;
		if (isProblematic1 -> val != - 10 and root -> val < last -> val)
			isProblematic2 = root;
		last = root;
		helper (root -> right);
	}
	void recoverTree (TreeNode *root) {
		helper (root);
		swap (isProblematic1 -> val, isProblematic2 -> val);
	}
};

