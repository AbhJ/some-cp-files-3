class Solution {
public:
	int f (vector <int> nums) {
		vector <int> pre = nums, suf = nums;
		for (int i = 1; i < nums.size(); i++) {
			pre[i] = gcd (pre[i - 1], pre[i]);
			suf[nums.size() - i - 1] = gcd (suf[nums.size() - i], suf[nums.size() - i - 1]);
		}
		int cnt = 0;
		for (int i = 0; i < nums.size() - 1; i++) {
			cnt += (pre[i] == suf[i + 1]);
		}
		return cnt;
	}
	int maxValidSplits (vector<int>& nums) {
		int ans = f (nums);
		for (int i = 0; i < nums.size(); i++) {
			int x = nums[i];
			nums.erase (nums.begin() + i);
			ans = max (f (nums), ans);
			nums.emplace (nums.begin() + i, x);
		}
		return ans;
	}
};