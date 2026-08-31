class Solution {
public:
	int minOperations (vector<int>& nums, int sum) {
		vector <long long> dp (sum + 1, 1e18);
		dp[0] = 0;
		for (auto num : nums) {
			auto _dp = dp;
			vector <long long> v;
			int c = 0;
			for (int i = num; i <= sum; i *= 2) {
				for (int j = i; j <= sum; j++)
					_dp [j] = min (dp[j - i] + c, _dp[j]);
				c++;
			}
			c = 0;
			for (int i = num; i; i /= 2) {
				for (int j = i; j <= sum; j++)
					_dp [j] = min (dp[j - i] + c, _dp[j]);
				c++;
			}
			swap (_dp, dp);
		}
		return (dp[sum] == 1e18 ? - 1 : dp[sum]);
	}
};