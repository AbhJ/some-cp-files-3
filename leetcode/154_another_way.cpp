class Solution {
public:
	int findMin (vector<int> &nums) {
		int n = nums.size(), l = 0, r = n - 1, m;
		while (l < r) {
			m = (l + r) / 2;
			if (nums[m] > nums[r])
				l = m + 1;
			else if (nums[m] == nums[r])
				r--;
			else
				r = m;
		}
		return nums[l];
	}
};
