vector<int>s;
int u;
bool dfs (TreeNode *A) {
	if (A == NULL)
		return 0;
	s.emplace_back (A->val);
	if (A->val == u)
		return 1;
	if (dfs (A->left))
		return 1;
	if (dfs (A->right))
		return 1;
	s.pop_back();
	return 0;
}
vector<int> Solution::solve (TreeNode *A, int B) {
	s.clear();
	u = B;
	dfs (A);
	return s;
}
