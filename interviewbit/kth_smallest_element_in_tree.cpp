int cnt, ans;
void f (TreeNode *A, int B) {
	if (A == NULL)
		return;
	f (A->left, B);
	cnt++;
	if (cnt == B)
		ans = A->val;
	f (A->right, B);
}
int Solution::kthsmallest (TreeNode *A, int B) {
	ans = cnt = 0;
	f (A, B);
	return ans;
}
