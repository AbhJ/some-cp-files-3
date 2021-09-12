class Solution {
public:
	vector<vector<int>>dp = vector<vector<int>>(1e4 + 1, vector<int>(1e2 + 1, - 1));

	int superEggDrop(int k, int n) {
		int l = 1, r = n, m;

		if (n <= 1 or k == 1)
			return n;

		if (~dp[n][k])
			return dp[n][k];

		int &ans = dp[n][k] = 1e9;

		while (r > l) {
			m = l + r + 1 >> 1;

			// WE GO DOWN MEANS EGG IS CRACKED
			int lef = superEggDrop(k - 1, m - 1);

			// WE GO UP MEANS EGG IS NOT CRACKED
			int rig = superEggDrop(k, n - m);

			if (lef <= rig)
				l = m;

			else
				r = m - 1;

			// FOR THE ANSWER WE MAY NOT BE
			// ALWAYS LUCKY
			// PER MOVE WE USE A CHANCE

			ans = min(ans, 1 + max(lef, rig));
		}

		return ans;
	}
};