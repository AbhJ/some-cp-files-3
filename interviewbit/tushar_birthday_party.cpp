int Solution::solve (const vector<int> &A, const vector<int> &B, const vector<int> &C) {
	int n = B.size();
	int cost = 0;
	vector<int>dp (1001, 1e9);
	dp[0] = 0;
	assert (n == C.size());
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j < n; j++)
			if (i + B[j] <= 1000)
				dp[i + B[j]] = min (dp[i + B[j]], dp[i] + C[j]);
	}
	for (auto i : A)
		cost += dp[i];
	return cost;
}
