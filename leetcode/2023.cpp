class Solution {
public:
	int numOfPairs (vector<string>& nums, string target) {
		int n = nums.size(), cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (i != j)
					cnt += (target == (nums[j] + nums[i]));
		}
		return cnt;
	}
};
