class Solution {
public:
	int maximumLength (vector<int>& nums, int k) {
		vector <unordered_map <int, int>> dp (k + 1);
		// dp [misses][lastInt] is the length of the longest subsequence till now that has
		// misses number of non-adjacent-equals and ends with lastInt
		vector <int> ans (k + 1);
		// ans [misses] is the absolute best of dp[misses] among all lastInts
		for (auto lastInt : nums) {
			auto _ans = ans;
			for (int misses = 0; misses <= k; misses++) {
				dp[misses][lastInt] += 1;
				// length increasing without any new misses
				if (misses)
					dp[misses][lastInt] = max (ans[misses - 1] + 1, dp[misses][lastInt]);
				// assuming new miss
				_ans[misses] = max (dp[misses][lastInt], _ans[misses]);
			}
			swap (ans, _ans);
		}
		return *max_element (ans.begin(), ans.end());
	}
};