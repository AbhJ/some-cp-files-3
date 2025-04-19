class Solution {
public:
	int maxSubarraySumCircular (vector<int>& nums) {
		int n = nums.size(), curMax = 0, ma = nums[0], curMin = 0, mi = nums[0],
		    sum = accumulate (nums.begin(), nums.end(), 0);
		for (int i = 0; i < nums.size(); i++) {
			curMax = max (nums[i], curMax + nums[i]);
			ma = max (curMax, ma);
			curMin = min (nums[i], curMin + nums[i]);
			mi = min (curMin, mi);
		}
		if (ma < 0)
			return ma;
		return max (sum - mi, ma);
	}
};