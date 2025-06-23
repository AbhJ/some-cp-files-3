class Solution {
public:
	int dp[1001][2];
	int f (int n, bool isFlat) {
		if (n < 0)
			return 0;
		if (n == 0) {
			if (isFlat)
				return 1;
			return 0;
		}
		if (dp[n][isFlat])
			return dp[n][isFlat];
		if (isFlat) {
			// case 1: vertical dom
			// case 2: trom
			// case 3: horizontal dom
			return dp [n][isFlat] = (f (n - 1, true) + 2LL * f (n - 2, false) + f (n - 2,
			                         true)) % (long long) (1e9 + 7LL);
		}
		// case 1: trom
		// case 2: horizontal dom
		return dp [n][isFlat] = (1LL * f (n - 1, false) + f (n - 1,
		                         true)) % (long long) (1e9 + 7LL);
	}
	int numTilings (int n) {
		return f (n, true);
	}
};