int dfs (TreeNode *A) {
	if ((A->left) == NULL and (A->right) == NULL)
		return 1;
	int ans = 1e9;
	if ((A->left) != NULL)
		ans = min (ans, dfs (A->left));
	if ((A->right) != NULL)
		ans = min (ans, dfs (A->right));
	return ans + 1;
}
int Solution::minDepth (TreeNode *A) {
	return dfs (A);
}
