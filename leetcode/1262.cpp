class Solution {
public:
	int maxSumDivThree (vector<int>& nums) {
		int n = nums.size();
		vector <vector <int>> dp (3, vector <int> (n + 1, - 1e9));
		dp[0][0] = 0;
		for (int j = 0; j < n; j++)
			for (int i = 0; i < 3; i++) {
				dp [i][j + 1] = max (dp[i][j + 1], dp[i][j]);
				dp[ (i + nums[j]) % 3][j + 1] = max (dp[ (i + nums[j]) % 3][j + 1],
				                                     dp[i][j] + nums[j]);
			}
		return dp[0][n];
	}
};