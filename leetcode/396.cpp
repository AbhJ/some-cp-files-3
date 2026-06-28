class Solution {
public:
	int maxRotateFunction (vector<int>& nums) {
		int sum = accumulate (nums.begin(), nums.end(), 0), cos = 0, n = nums.size(),
		    ans = - 2e9;
		for (int i = 0; i < n; i++) {
			cos += i * nums[i];
		}
		for (int i = n - 1; ~i; i--) {
			cos += sum - n * nums[i];
			ans = max (cos, ans);
		}
		return ans;
	}
};