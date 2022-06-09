string s;
int n, dp[1000][1000];
int f (int pos, int B, int cnt_B = 0, int cnt_W = 0) {
	if (pos == n)
		return B == 0 ? cnt_B * cnt_W : 1e9;
	if (B <= 0)
		return 1e9;
	if (~dp[pos][B])
		return dp[pos][B];
	int cnt = 1e9;
	for (int i = pos; i < n; i++) {
		cnt_B += s[i] == 'B';
		cnt_W += s[i] == 'W';
		cnt = min (cnt, cnt_W * cnt_B + f (i + 1, B - 1, 0, 0));
	}
	return dp[pos][B] = cnt;
}
int Solution::arrange (string A, int B) {
	int m = A.length();
	s = A;
	n = m;
	memset (dp, - 1, sizeof dp);
	int ans = f (0, B);
	return ans < 1e9 ? ans : - 1;
}
