class Solution {
public:
	void creator(int i, int m, vector<vector<int>>& tot) {
		if (i == m)
			return;
		vector<vector<int>> v = tot;
		tot.clear();
		for (int j = 0; j < 3; j++) {
			for (auto k : v) if (k.empty() or k.back() != j) {
					k.push_back(j);
					tot.push_back(k);
				}
		}
		creator(i + 1, m, tot);
	}
	long long int dp[1001][1001];
	int dfs(int i, int pat, int n, vector<vector<int>>&a) {
//         a is adjacency list and tot is the vector of vector of patterns of size m
		if (i == n)
			return 1;
		if (~dp[i][pat])
			return dp[i][pat];
		long long int cnt = 0;
		for (int newPat : a[pat]) {
			cnt += dfs(i + 1, newPat, n, a);
			cnt %= (long long int)(1e9 + 7);
		}
		return dp[i][pat] = (int)cnt;
	}
	int colorTheGrid(int m, int n) {
		vector<vector<int>> tot(1);
		creator(0, m, tot);
		int cnt = tot.size();
		vector<vector<int>>a(cnt);
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < cnt; j++) {
				int flag = 0;
				for (int k = 0; k < m; k++) {
					if (tot[i][k] == tot[j][k])
						flag = 1;
				}
				if (flag == 0)
//                     We can easily insert the j th pattern after the ith pattern
					a[i].push_back(j);
			}
		}
		memset(dp, - 1LL, sizeof dp);
		long long int cntFin = 0;
		for (int i = 0; i < cnt; i++) {
//             forcing first pattern to take each value to have all cases in our answer
			cntFin += dfs(0, i, n - 1, a);
			cntFin %= (long long int)(1e9 + 7);
		}
		return (int)cntFin;
	}
};