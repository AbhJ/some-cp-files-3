class Solution {
public:
	int maxProduct (string s) {
		int n = s.length(), ans = 0;
		function <int (string&)> isPal = [&] (string & s) -> int {
			return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
		};
		int siz = 1 << n;
		vector<int> dp (siz);
		for (int m = 0; m < siz; m++) {
			string t;
			for (int i = 0; i < n; i++) {
				if ((m >> i) & 1)
					t += s[i];
			}
			if (isPal (t))
				dp[m] = t.length();
		}
		for (int m = siz - 1; m > - 1; m--) {
			if (dp[m] * (siz - 1 - dp[m]) > ans) {
				int m2 = m ^ (siz - 1);
				for (int sub = m2; sub; sub = (sub - 1)&m2)
					ans = max (ans, dp[m] * dp[sub]);
			}
		}
		return ans;
	}
};
