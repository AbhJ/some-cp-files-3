class Solution {
public:
	int maxProfit (vector<int>& prices) {
		int n = prices.size();
		vector<vector<long long>> dp (2, vector <long long> (n, - 1e18));
		// dp [0][i] is for buying
		// dp [1][i] is for selling
		for (int i = 0; i < n; i++) {
			dp[0][i] = std::max (i < 1 ? (long long) - 1e18 : dp[0][i - 1],
			                     (i < 2 ? 0 : dp[1][i - 2]) - prices[i]);
			dp[1][i] = std::max (i < 1 ? 0 : dp[1][i - 1],
			                     (i < 1 ? 0 : dp[0][i - 1] + prices[i]));
		}
		return std::max (dp[0][n - 1], dp[1][n - 1]);
	}
};