vector<vector<int> > Solution::solve (int K, vector<vector<int> > &A) {
	int dp[A.size() + 10][A[0].size() + 10][K + 3], n = A.size(), m = A[0].size();
	for (int i = 0; i < A.size() + 10; i++)
		for (int j = 0; j < A[0].size() + 10; j++)
			for (int k = 0; k <= K + 3; k++)
				dp[i][j][k] = 0;
	for (int k = 0; k <= K; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (k == 0) {
					dp[i][j][k] = A[i][j];
					continue;
				}
				if (i != 0)
					dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j][k - 1]);
				if (j != 0)
					dp[i][j][k] = max (dp[i][j][k], dp[i][j - 1][k - 1]);
				if (i != n - 1)
					dp[i][j][k] = max (dp[i][j][k], dp[i + 1][j][k - 1]);
				if (j != m - 1)
					dp[i][j][k] = max (dp[i][j][k], dp[i][j + 1][k - 1]);
				A[i][j] = max (A[i][j], dp[i][j][k]);
			}
	return A;
}
