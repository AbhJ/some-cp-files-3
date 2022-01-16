class Solution {
public:
	int minKBitFlips (vector<int> &nums, int k) {
		int n = nums.size(), ans = 0, f = 1;
		vector<bool>change (n);
		for (int i = 0; i < n; i++) {
			f ^= change[i];
			if (nums[i] ^ f) {
				if (i + k > n)
					return - 1;
				change[i + k] = 1;
				f ^= 1;
				ans++;
			}
		}
		return ans;
	}
};
