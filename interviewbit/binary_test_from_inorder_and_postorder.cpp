/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *f (vector<int> &inor, map<int, int> &posi, vector<int> &post, int n, int l, int r, int &cnt) {
	if (~cnt == 0 or l > r)
		return NULL;
	int pos = posi[post[cnt]];
	TreeNode *cur = new TreeNode (post[cnt]);
	cnt--;
	cur -> right = f (inor, posi, post, n, pos + 1, r, cnt);
	cur -> left = f (inor, posi, post, n, l, pos - 1, cnt);
	return cur;
}
TreeNode *Solution::buildTree (vector<int> &A, vector<int> &B) {
	int n = A.size();
	assert (n == B.size());
	map<int, int>posi;
	for (int i = 0; i < n; i++)
		posi[A[i]] = i;
	int cnt = n - 1;
	return f (A, posi, B, n, 0, n - 1, cnt);
}

