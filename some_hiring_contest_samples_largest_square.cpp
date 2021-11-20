int largestArea (vector<vector<int>> samples) {
	int row = samples.size(), col = samples[0].size(), len = 0;
	vector<vector<int>> dp (row + 1, vector<int> (col + 1, 0));
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (samples[i - 1][j - 1] == 1) {
				dp[i][j] = 1 + min ({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) ;
				len = max (len, dp[i][j]);
			}
		}
	}
	return len;
}
