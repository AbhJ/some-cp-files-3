class Solution {
public:
	int findMin (vector<int> &nums) {
		int n = nums.size(), l = 0, r = n - 1, m;
		if (nums[l] < nums[r])
			return nums[l];
		while (l < r) {
			m = ((l + r) >> 1);
			if (nums[m] >= nums[l] and nums[r] < nums[m])
				l = m + 1;
			else
				r = m;
		}
		return nums[r];
	}
};
