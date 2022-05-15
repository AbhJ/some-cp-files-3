#include <bits/stdc++.h>
vector<vector<int>>sp;
map<int, int>m;
TreeNode *f (vector<int> &A, int l, int r) {
	if (l > r)
		return NULL;
	int R = log2 (r - l + 1);
	int val = max (sp[l][R], sp[r - (1 << R) + 1][R]);
	int pos = m[val];
	TreeNode *h = new TreeNode (val);
	if (l == r)
		return h;
	h->left = f (A, l, pos - 1);
	h->right = f (A, pos + 1, r);
	return h;
}
TreeNode *Solution::buildTree (vector<int> &A) {
	if (A.empty() == 1)
		return NULL;
	m.clear();
	int cnt = 0;
	for (auto i : A)
		m[i] = cnt++;
	sp = vector<vector<int>> (A.size() + 10, vector<int> (35, 0));
	for (int i = 0; i < A.size(); i++)
		sp[i][0] = A[i];
	for (int j = 1; j <= log2 (A.size()) + 1; j++)
		for (int i = 0; i + (1 << j) <= A.size(); i++)
			sp[i][j] = max (sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
	return f (A, 0, A.size() - 1);
}
