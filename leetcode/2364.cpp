class Solution {
public:
	long long countBadPairs (vector<int>& nums) {
		map <int, int> m;
		long long ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			ans += m[nums[i] - i]++;
		}
		return ((long long) nums.size() * (nums.size() - 1) / 2) - ans;
	}
};