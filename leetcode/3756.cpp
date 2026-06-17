class Solution {
public:
	int cos (vector<int> nums, int t) {
		int ans = 0;
		for (auto i = nums.begin(); i != nums.end() - 1; i++) {
			if (*i != t) {
				*i = t;
				* (i + 1) = - * (i + 1);
				ans++;
			}
		}
		if (nums.back() != t)
			return 1e9;
		return ans;
	}
	bool canMakeEqual (vector<int>& nums, int k) {
		int p = 0, n = 0;
		for (auto &i : nums) {
			p += i == 1;
			n += i == - 1;
		}
		if ((p & 1) and (n & 1))
			return false;
		return cos (nums, 1) <= k or cos (nums, - 1) <= k;
	}
};