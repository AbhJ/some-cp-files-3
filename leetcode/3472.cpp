class Solution {
public:
	int dp[201][201][201];
	int c (char x, char y) {
		return min (abs (x - y), 26 - abs (x - y));
	}
	int f (string &s, int i, int j, int k) {
		if (k < 0)
			return - 1e9;
		if (i == j)
			return 1;
		if (i > j)
			return 0;
		if (~ dp[i][j][k])
			return dp[i][j][k];
		int ans = 0;
		return dp[i][j][k] = max ({2 + f (s, i + 1, j - 1, k - c (s[i], s[j])), f (s, i + 1, j, k), f (s, i, j - 1, k)});
	}
	int longestPalindromicSubsequence (string s, int k) {
		memset (dp, - 1, sizeof dp);
		return f (s, 0, (int) s.length() - 1, k);
	}
};