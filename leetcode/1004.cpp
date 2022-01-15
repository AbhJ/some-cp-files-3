class Solution {
public:
	int longestOnes (vector<int> &nums, int k) {
		int n = nums.size(), l = - 1, r = - 1, cntZeros = 0, ans = 0;
		// the subsequence that we are considering is l + 1 to r both included
		while (++r < n) {
			cntZeros += nums[r] == 0;
			while (cntZeros > k and l < r)
				cntZeros -= nums[++l] == 0;
			ans = max (ans, r - l);
		}
		return ans;
	}
};

