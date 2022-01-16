class Solution {
public:
	int findUnsortedSubarray (vector<int> &nums) {
		int n = nums.size(), mi = nums[n - 1], ma = nums[0], R = - 1, L = 0;
		for (int i = 0; i < n; i++) {
			if (ma > nums[i])
				R = i;
			ma = max (nums[i], ma);
		}
		for (int i = n - 1; i > - 1; i--) {
			if (mi < nums[i])
				L = i;
			mi = min (nums[i], mi);
		}
		return R - L + 1;
	}
};
