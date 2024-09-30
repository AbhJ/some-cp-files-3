int Solution::solve (vector<int> &A, int B) {
	vector<vector<long long>> dp (A.size() + 1,
	                              vector<long long> (min ((int) A.size(), B) + 1));
	for (int j = 1; j <= min ((int) A.size(), B); j++) {
		long long maxProfitAfterBuy = - 1e18;
		for (int i = 0; i < A.size(); i++) {
			// dp[i][j] is the profit after selling at the ith day and having j total transactions
			dp[i + 1][j] = max (maxProfitAfterBuy + A[i], dp[i][j]);
			maxProfitAfterBuy = max (dp[i][j - 1] - A[i], maxProfitAfterBuy);
		}
	}
	return (int) dp.back().back();
}