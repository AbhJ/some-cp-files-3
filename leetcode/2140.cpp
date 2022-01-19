class Solution {
public:
	long long mostPoints (vector<vector<int>> &questions) {
		int n = questions.size();
		vector<long long>dp (n);
		for (int i = n - 1; i > - 1; i--) {
			long long brainpower = questions[i][1], points = questions[i][0];
			dp[i] = max (dp[i], (i == n - 1 ? 0 : dp[i + 1]));
			if (brainpower + i + 1 < n)
				dp[i] = max (dp[brainpower + i + 1] + points, dp[i]);
			else
				dp[i] = max (points, dp[i]);
		}
		return dp[0];
	}
};
