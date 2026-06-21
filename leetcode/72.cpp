class Solution {
public:
	int minDistance (string s, string t) {
		int n = s.length(), m = t.length();
		s = '#' + s;
		t = '#' + t;
		vector <vector<int>> dp (n + 1, vector <int> (m + 1, 1e9));
		for (int i = 0; i < n; i++)
			dp[i][0] = i;
		for (int i = 0; i < m; i++)
			dp[0][i] = i;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				dp [i][j] = min ({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
				if (s[i] == t[j])
					dp[i][j] = min (dp[i - 1][j - 1], dp[i][j]);
			}
		if (n == 0 or m == 0)
			return n + m;
		return dp[n][m];
	}
};