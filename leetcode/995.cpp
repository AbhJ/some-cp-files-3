class Solution {
public:
	int minKBitFlips (vector<int> &nums, int k) {
		int f = 1, cnt = 0, n = nums.size();
		vector<int> flip (n + 1);
		for (int i = 0; i < n; i++) {
			f ^= flip[i];
			if (nums[i] ^ f) {
				if (i + k > n)
					return - 1;
				flip[i + k] = 1;
				f ^= 1;
				cnt++;
			}
		}
		return cnt;
	}
};
