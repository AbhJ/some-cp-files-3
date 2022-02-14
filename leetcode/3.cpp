class Solution {
public:
	int lengthOfLongestSubstring (string s) {
		int dp[600], l = - 1, ans = 0;
		fill (dp, dp + 600, - 1);
		for (int r = 0; r < s.length(); r++) {
			if (~dp[s[r]])
				l = max (dp[s[r]], l);
			dp[s[r]] = r;
			ans = max (ans, r - l);
		}
		return ans;
	}
};
