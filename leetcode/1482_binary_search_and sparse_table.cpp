class Solution {
public:
	int m, k;
	int get (int l, int r, vector<vector<int>>& sp) {
		int j = log2 (r - l + 1);
		return max (sp[l][j], sp[r - (1 << j) + 1][j]);
	}
	int f (int v, vector<vector<int>>& sp) {
		int n = sp.size();
		vector<int>dp (n, 0);
		for (int i = k - 1; i < n; i++) {
			int l = i - (k - 1);
			int r = i;
			if (get (l, r, sp) <= v) {
				if (l == 0)
					dp[i] = 1;
				else
					dp[i] = 1 + dp[l - 1];
			}
			if (i != 0)
				dp[i] = max (dp[i], dp[i - 1]);
			if (dp[i] >= m)
				return 1;
		}
		return 0;
	}
	int minDays (vector<int>& bloomDay, int group, int x) {
		int n = bloomDay.size();
		m = group, k = x;
		vector<vector<int>> sp (n, vector<int> (35, 0));
		for (int i = 0; i < n; i++)
			sp[i][0] = bloomDay[i];
		for (int j = 1; j <= log2 (n) + 1; j++) {
			for (int i = 0; i + (1 << j) <= n; i++)
				sp[i][j] = max (sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
		}
		int l = 1, r = 1e9;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (f (m, sp))
				r = m;
			else
				l = m;
		}
		if (f (l, sp))
			return l;
		if (f (r, sp))
			return r;
		return -1;
	}
};
