/**
 * @author      : abj (abj@abj)
 * @file        : 1997
 * @created     : Wednesday Sep 08, 2021 16:03:55 IST
 */

class Solution {
public:
	int firstDayBeenInAllRooms (vector<int>& nextVisit) {
		int n = nextVisit.size();
		vector<long long>dp (n);
		for (int i = 1; i < n; i++) {
			dp[i] = dp[i - 1] + 2 + dp[i - 1] - dp[nextVisit[i - 1]];
			dp[i] = dp[i] + (long long) (1e9 + 7);
			dp[i] = dp[i] % (long long) (1e9 + 7);
		}
		return dp[n - 1];
	}
};
