class Solution {
public:
	int twoEggDrop (int n) {
		vector <int> dp (n + 1, 1e9);
		dp [0] = 0;
		for (int i = 1; i <= n; i++)
			for (int f = 1; f <= i; f++) {
				dp [i] = min (dp[i], max (1 + dp[i - f], f));
			}
		return dp [n];
	}
};