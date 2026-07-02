class Solution {
public:
	int n, m;
	vector <vector<int>> dp;
	vector <vector<bool>> vis;
	vector <int> v;
	void f (int i, int k) {
		if (k < 0 or vis[i][k])
			return;
		for (int j = 0; j < i; j++) {
			if (v[i] != v[j] and k > 0) {
				f (j, k - 1);
				dp[i][k] = max (1 + dp[j][k - 1], dp[i][k]);
			}
			else if (v[i] == v[j]) {
				f (j, k);
				dp[i][k] = max (1 + dp[j][k], dp[i][k]);
			}
		}
		vis [i][k] = 1;
	}
	int maximumLength (vector<int>& nums, int k) {
		n = nums.size();
		m = k;
		v = nums;
		dp = vector <vector<int>> (n + 1, vector<int> (m + 1));
		vis = vector <vector<bool>> (n + 1, vector<bool> (m + 1));
		for (int i = 0; i <= n; i++)
			// for (int j = 0; j <= k; j++)
			dp[i][0] = 1;
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int _k = 0; _k <= k; _k++) {
				f (i, _k);
				ans = max (dp[i][_k], ans);
			}
		return ans;
	}
};