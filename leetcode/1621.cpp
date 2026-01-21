class Solution {
public:
	int M = 1e9 + 7;
	int numberOfSets (int n, int k) {
		vector <vector<int>> dp (n + 1, vector<int> (k + 1)), pre (n + 1,
		        vector<int> (k + 1));
		for (int i = 1; i <= n; i++)
			dp[i][1] = (i * (i + 1)) / 2;
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= k; j++) {
				if (i >= j)
					pre[i][j] = (pre[i - 1][j] + dp[i - 1][j - 1]) % M;
				// // ii to i being one segment
				// for (int ii = j - 1; ii < i; ii++)
				//     dp[i][j] = (dp[i][j] + dp[ii][j - 1]) % M;
				dp[i][j] = (pre[i][j] + dp[i - 1][j]) % M;
			}
		}
		return dp[n - 1][k];
	}
};