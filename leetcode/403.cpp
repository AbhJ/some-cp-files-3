class Solution {
public:
	bool canCross(vector<int>& a) {
		int n = a.size();
		vector <set<long long>> dp(n + 1);
		dp[0].emplace(0);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				long long dis = (long long) a[i - 1] - (long long) (j != 0 ? a[j - 1] : 0);
				if (dp[j].count(dis))
					dp[i].emplace(dis);
				if (dp[j].count(dis - 1))
					dp[i].emplace(dis);
				if (dp[j].count(dis + 1))
					dp[i].emplace(dis);
			}
		}
		return !dp[n].empty();
	}
};