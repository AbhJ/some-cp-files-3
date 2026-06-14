class Solution {
public:
	// vector<vector<int>> v;
	// int n, m, k;
	// vector <vector<int>> dp;
	// // cos[i][j] == i th tire for j times
	// vector <vector <int>> cos;
	// int f (int i, int cur, int la) {

	// }
	int minimumFinishTime (vector<vector<int>>& tires, int changeTime, int m) {
		// v = tires;
		int n = tires.size();
		int ans = 2e9;
		// dp.resize (n, vector <int> (numLaps, - 1));
		vector <long long> dp (m + 1, 2e9);
		vector <vector<long long>> cos (n + 1, vector<long long> (30));
		for (int i = 0; i < n; i++) {
			cos[i][0] = tires[i][0];
			for (int j = 1; j < 30; j++) {
				if (cos[i][j - 1] > 2e9)
					cos[i][j] = 2e9;
				else
					cos[i][j] = cos[i][j - 1] * tires[i][1];
			}
			for (int j = 1; j < 30; j++) {
				cos[i][j] = cos[i][j - 1] + cos[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			if (i < 30)
				for (int j = 0; j < n; j++) {
					dp [i] = min (cos[j][i], dp[i]);
				}
			for (int j = 0; j < min (30, i); j++) {
				dp[i] = min (dp[i - j - 1] + changeTime + dp[j], dp[i]);
			}
		}
		return dp[m - 1];
	}
};