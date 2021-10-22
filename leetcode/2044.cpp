class Solution {
public:
	int countMaxOrSubsets (vector<int>& nums) {
		int n = nums.size();
		vector<int> cnt (1e6 + 1);
		for (long long m = (1LL << n) - 1; ~m; m--) {
			int val = 0;
			for (int i = 0; i < n; i++)
				if (m & (1LL << i))
					val |= nums[i];
			cnt[val]++;
		}
		for (int i = 1e6; ~i; i--) {
			if (cnt[i] != 0)
				return cnt[i];
		}
		return 0;
	}
};
