class Solution {
public:
	int minPairSum (vector<int>& nums) {
		sort (nums.begin(), nums.end());
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			ans = max (nums[i] + nums[nums.size() - i - 1], ans);
		}
		return ans;
	}
};