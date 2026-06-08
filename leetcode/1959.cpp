class Solution {
public:
	int dp [201][201], n;
	vector <int> a;
	int f (int i, int m) {
		if (i == n)
			return 0;
		if (m == - 1)
			return 1e9;
		if (dp[i][m] != 1e9)
			return dp[i][m];
		int cur_ma = 0, pre_sum = 0;
		for (int j = i; j < n; j++) {
			cur_ma = max (a[j], cur_ma);
			pre_sum += a[j];
			dp[i][m] = min ((j - i + 1) * cur_ma - pre_sum + f (j + 1, m - 1), dp[i][m]);
		}
		return dp[i][m];
	}
	int minSpaceWastedKResizing (vector<int>& nums, int m) {
		// dp[i][j] is answer for first i elements with total resizes j
		fill (&dp[0][0], &dp[0][0] + 201 * 201, 1e9);
		n = nums.size();
		a = nums;
		return f (0, m);
	}
};