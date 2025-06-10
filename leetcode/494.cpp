class Solution {
public:
	int findTargetSumWays (vector<int>& nums, int target) {
		int n = nums.size(), cnt = 0, total = accumulate (nums.begin(), nums.end(), 0);
		if (n < 12) {
			for (long long mask = 0; mask < (1LL << n); mask++) {
				int tmp = 0;
				for (int i = 0; i < n; i++) {
					if (mask & (1LL << i))
						tmp += nums[i];
					else
						tmp -= nums[i];
				}
				cnt += target == tmp;
			}
			return cnt;
		}
		// target = sumP - sumN
		// total = sumP + sumN
		// (total + target) = 2 * sumP
		if ((total + target) & 1)
			return 0;
		int newTarget = (total + target) >> 1;
		vector <int> dp (newTarget + 1);
		dp[0] = 1;
		for (auto cur : nums) {
			auto newDp = dp;
			for (int i = 0; i <= newTarget; i++) if (i + cur <= newTarget) {
					newDp[i + cur] = dp[i] + newDp[i + cur];
				}
			swap (dp, newDp);
		}
		return dp.back();
	}
};