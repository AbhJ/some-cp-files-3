class Solution {
public:
	long long minOperationsToMakeMedianK (vector<int>& nums, int k) {
		int n = nums.size();
		sort (nums.begin(), nums.end());
		long long cur = nums[n >> 1], ans = 0;
		if (cur == k)
			return 0;
		if (cur < k)
			for (int i = (n >> 1); i < n; i++) {
				if (nums[i] >= k)
					break;
				ans += k - nums[i];
			}
		else
			for (int i = (n >> 1); ~i; i--) {
				if (nums[i] <= k)
					break;
				ans += nums[i] - k;
			}
		return ans;
	}
};