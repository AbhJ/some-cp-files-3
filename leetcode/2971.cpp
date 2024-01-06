class Solution {
public:
	long long largestPerimeter (vector<int>& nums) {
		int n = nums.size();
		vector<long long> prefix_sums (n);
		sort (nums.begin(), nums.end());
		for (int i = 0; i < n; i++) {
			prefix_sums[i] = (i == 0 ? 0 : prefix_sums[i - 1]) + nums[i];
		}
	}
};