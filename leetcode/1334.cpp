class Solution {
public:
	int findTheCity (int n, vector<vector<int>>& edges, int distanceThreshold) {
		// find all pairs of distances using floyd warshall
		// select ones below threshold
		// then select smallest with greatest pos
		vector <vector<int>> dp (n, vector<int> (n, 1e9));
		for (int i = 0; i < n; i++) {
			dp[i][i] = 0;
		}
		for (auto v : edges) {
			dp[v[0]][v[1]] = dp[v[1]][v[0]] = v[2];
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dp[i][j] = min (dp[i][k] + dp[k][j], dp[i][j]);
				}
			}
		}
		int cntReachableMin = 1e9, ans = 0;
		for (int i = 0; i < n; i++) {
			int cntReachable = 0;
			for (int j = 0; j < n; j++) {
				if (i == j or dp[i][j] > distanceThreshold)
					continue;
				cntReachable++;
			}
			if (cntReachable <= cntReachableMin) {
				cntReachableMin = cntReachable;
				ans = i;
			}
		}
		return ans;
	}
};