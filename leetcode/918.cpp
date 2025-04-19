class Solution {
public:
	int kadane (vector<int> nums) {
		int n = nums.size(), l = 0, r = 0, cur = nums[0], ans = nums[0], last = 0;
		nums.resize (2 * n);
		for (int i = 0; i < n; i++)
			nums[i + n] = nums[i];
		for (int i = 1; i < 2 * n; i++) {
			cur += nums[i];
			if (ans < cur and i - last + 1 <= n)
				l = last, r = i, ans = cur;
			if (cur < nums[i]) {
				cur = nums[i];
				last = i;
			}
			if (ans < cur and i - last + 1 <= n)
				l = last, r = i, ans = cur;
		}
		return ans;
	}
	int maxSubarraySumCircular (vector<int>& nums) {
		int maxNormal = kadane (nums), sum = 0;
		for (int i = 0; i < nums.size(); i++)
			nums[i] = - nums[i], sum -= nums[i];
		if (maxNormal < 0)
			return maxNormal;
		return max (maxNormal, kadane (nums) + sum);
	}
};