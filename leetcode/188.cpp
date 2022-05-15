class Solution {
public:
	int maxProfit (int k, vector<int> &prices) {
		int n = prices.size();
		int dp[n + 1][k + 1];
		memset (dp, 0, sizeof dp);
		for (int j = 1; j <= k; j++) {
			int ma = -1e9;
			for (int i = 1; i <= n; i++) {
				dp[i][j] = max (dp[i - 1][j], ma + prices[i - 1]);
				ma = max (ma, dp[i - 1][j - 1] - prices[i - 1]);
			}
		}
		return dp[n][k];
	}
};
