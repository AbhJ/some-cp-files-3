class Solution {
public:
	long long maxRunTime (int n, vector<int> &batteries) {
		sort (batteries.begin(), batteries.end());
		int len = batteries.size();
		long long l = 0, r = 1e14, m, ans;
		while (l < r) {
			m = (l + r + 1) / 2;
			ans = 0;
			for (long long i : batteries)
				ans += min (i, m);
			if (ans >= 1LL * n * m)
				l = m;
			else
				r = m - 1;
		}
		return l;
	}
};
