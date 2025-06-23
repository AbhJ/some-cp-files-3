class Solution {
public:
	double champagneTower (int poured, int query_row, int query_glass) {
		vector <vector <double>> dp (query_row + 2, vector <double> (query_row + 2));
		dp [0][0] = poured;
		if (query_row == 0)
			return min (poured, 1);
		for (int i = 1; i <= query_row + 1; i++) {
			for (int j = 0; j <= i; j++) {
				if (dp[i - 1][j] > 1) {
					dp[i][j] += (dp[i - 1][j] - 1) / 2;
					dp[i][j + 1] += (dp[i - 1][j] - 1) / 2;
					dp[i - 1][j] = 1;
				}
			}
		}
		return dp[query_row][query_glass];
	}
};