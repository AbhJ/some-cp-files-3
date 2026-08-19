class Solution {
public:
	int dp [2002][2002];
	int longestPalindrome (string word1, string word2) {
		int n = word1.length(), m = word2.length(), ans = 0;
		// following solution works only when first half from word1 and second half from word2
		// i misread problem statement
		// reverse (word2.begin(), word2.end());
		// for (int i = 0; i < n; i++)
		//     for (int j = 0; j < m; j++) {
		//         if (word1[i] == word2[j]) {
		//             dp[i][j] = max (((i == 0 or j == 0) ? 0 : dp[i - 1][j - 1]) + 1, dp[i][j]);
		//         }
		//         dp[i][j] = max ({(i == 0 ? 0 : dp[i - 1][j]), (j == 0 ? 0 : dp[i][j - 1]), dp[i][j]});
		//         if (word1[i] != word2[j])
		//             continue;
		//         if (i != n - 1 or j != m - 1)
		//             ans = max (dp[i][j] * 2 + 1, ans);
		//         else
		//             ans = max (dp[i][j] * 2, ans);
		//     }
		// return ans;
		string w = word1 + word2;
		for (int len = 2; len <= n + m; len++) {
			for (int i = 0; i < n + m; i++) {
				int j = i + len - 1;
				if (j > n + m - 1)
					break;
				if (w[i] == w[j])
					dp[i][j] = max ((i + 1 == j - 1 ? 1 : dp[i + 1][j - 1]) + 2, dp[i][j]);
				dp[i][j] = max ({ (i + 1 == j ? 1 : dp[i + 1][j]), dp[i][j - 1], dp[i][j]});
				if (i < n and j > n - 1 and w[i] == w[j])
					ans = max (dp[i][j], ans);
			}
		}
		return ans;
	}
};