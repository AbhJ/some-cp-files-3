class Solution {
public:
	vector<int> a, dp;
	int n, ans;
	void dfs (int cur, int moves) {
		if (cur == n)
			ans = min (ans, moves);
		if (cur >= n)
			return;
		if (dp[cur] <= moves)
			return;
		// we already reached this node faster before
		int ans = 1e9;
		dp[cur] = moves;
		for (int dx = 1; dx <= 6 and cur + dx <= n; dx++) {
			int des = cur + dx;
			if (a[des] == - 1)
				dfs (des, moves + 1);
			else
				dfs (a[des], moves + 1);
		}
	}
	int snakesAndLadders (vector<vector<int>>& board) {
		reverse (board.begin(), board.end());
		int si = board.size();
		n = si * si;
		bool x = 0;
		a = {- 1};
		dp.resize (n + 10, 1e9);
		ans = 1e9;
		for (int i = 0; i < si; i++) {
			x ^= 1;
			if (x)
				for (int j = 0; j < si; j++) {
					a.emplace_back (board[i][j]);
				}
			else
				for (int j = si - 1; j > - 1; j--) {
					a.emplace_back (board[i][j]);
				}
		}
		dfs (1, 0);
		return ans == 1e9 ? - 1 : ans;
	}
};