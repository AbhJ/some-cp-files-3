int dp[505][505][2];
int f (int l, int r, vector<int> &A, int x = 1) {
	int i = l, j = r;
	if (l > r)return dp[i][j][x] = 0;
	if (dp[i][j][x] != -1)return dp[i][j][x];
	if (x == 0) {
		return dp[l][r][x] = min (f (l + 1, r, A, 1), f (l, r - 1, A, 1));
	}
	return dp[l][r][x] = max (A[l] + f (l + 1, r, A, 0), A[r] + f (l, r - 1, A, 0));
}
int Solution::maxcoin (vector<int> &A) {
	for (int i = 0; i <= A.size(); i++)
		for (int j = 0; j <= A.size(); j++)
			for (int x = 0; x < 2; x++)
				dp[i][j][x] = -1;
	return f (0, A.size() - 1, A);
}