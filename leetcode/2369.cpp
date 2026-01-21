class Solution {
public:
	bool validPartition (vector<int>& nums) {
		int n = nums.size();
		vector <bool> dp (n + 1);
		dp [0] = 1;
		for (int i = 2; i <= n; i++) {
			if (nums[i - 1] == nums[i - 2])
				dp[i] = dp[i - 2];
			if (i >= 3 and nums[i - 1] == nums[i - 2] and nums[i - 1] == nums[i - 3])
				dp[i] = dp[i - 3] or dp[i];
			if (i >= 3 and nums[i - 1] == nums[i - 2] + 1
			        and nums[i - 1] == nums[i - 3] + 2)
				dp[i] = dp[i - 3] or dp[i];
		}
		return dp [n];
	}
};