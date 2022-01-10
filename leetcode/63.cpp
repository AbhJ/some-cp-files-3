class Solution {
public:
	int uniquePathsWithObstacles (vector<vector<int>> &A) {
		int n = A.size(), m = A[0].size();
		vector<vector<int>> dp (n, vector<int> (m));
		dp[0][0] = (!A[0][0]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (A[i][j] == 1)
					continue;
				if (j != 0)
					dp[i][j] += dp[i][j - 1];
				if (i != 0)
					dp[i][j] += dp[i - 1][j];
			}
		}
		return dp[n - 1][m - 1];
	}
};
