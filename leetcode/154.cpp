class Solution {
public:
	int findMin (vector<int> &nums) {
		int n = nums.size(), l, r, m;
		l = 0, r = n - 1;
		while (r > l) {
			m = ((l + r) >> 1);
			if (nums[m] < nums[l])
				r = m;
			else
				l = m + 1;
		}
		while (r != 0 and nums[r - 1] <= nums[r])
			r--;
		return nums[r];
	}
};
