class Solution {
public:
	int firstMissingPositive (vector<int> &nums) {
		int cntOne = count (nums.begin(), nums.end(), 1), n = nums.size();
		if (cntOne == 0)
			return 1;
		for (int i = 0; i < n; i++) {
			if (nums[i] < 1 or nums[i] > n)
				nums[i] = 1;
		}
		for (int i = 0; i < n; i++)
			nums[abs (nums[i]) - 1] = - abs (nums[abs (nums[i]) - 1]);
		for (int i = 0; i < n; i++) {
			if (nums[i] > 0)
				return i + 1;
		}
		return n + 1;
	}
};
