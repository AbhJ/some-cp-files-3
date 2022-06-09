TreeNode *Solution::invertTree (TreeNode *A) {
	if (A == NULL)
		return A;
	TreeNode *left = A -> left, *right = A -> right;
	invertTree (A -> left);
	invertTree (A -> right);
	A -> right = left;
	A -> left = right;
	return A;
}
