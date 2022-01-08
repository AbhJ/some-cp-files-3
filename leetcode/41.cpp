class Solution {
public:
	int firstMissingPositive (vector<int> &nums) {
		int n = nums.size(), cnt = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			cnt1 += nums[i] == 1;
			if (nums[i] < 1 or nums[i] > n)
				nums[i] = 1, cnt++;
		}
		if (cnt1 == 0)
			return 1;
		for (int i = 0; i < n; i++) {
			int pos = abs (nums[i]) - 1;
			nums[pos] = - abs (nums[pos]);
		}
		if (cnt == n)
			return 1;
		for (int i = 0; i < n; i++) {
			if (nums[i] < 0)
				continue;
			return i + 1;
		}
		return n + 1;
	}
};
