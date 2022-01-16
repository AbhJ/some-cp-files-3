class Solution {
public:
	int minCost (int n, vector<int> &cuts) {
		if (cuts.empty())
			return 0;
		if (*max_element (cuts.begin(), cuts.end()) != n)
			cuts.emplace_back (n);
		if (*min_element (cuts.begin(), cuts.end()) != 0)
			cuts.emplace_back (0);
		int len = cuts.size();
		vector<vector<int>>dp (len + 1, vector<int> (len + 1, 1e9));
		sort (cuts.begin(), cuts.end());
		// dp[i][j] is the cost to cut from i to j
		for (int i = 0; i < len; ++i)
			dp[i][i + 1] = 0;
		for (int i = len; i > 0; i--) {
			for (int j = i + 2; j <= len; j++) {
				for (int k = i + 1; k < j; k++)
					dp[i][j] = min (dp[i][j], dp[i][k] + dp[k][j] + cuts[j - 1] - cuts[i - 1]);
			}
		}
		return dp[1][len];
	}
};
