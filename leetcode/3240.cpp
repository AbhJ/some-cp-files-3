class Solution {
public:
	int minFlips (vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size(), x = 0;
		int nr = (n / 2) - 1, mr = (m / 2) - 1, ans = 0, cnt;
		bool leverage = false;
		for (int i = 0; i <= nr; i++)
			for (int j = 0; j <= mr; j++) {
				cnt = grid[i][j] + grid[n - 1 - i][j] + grid[n - 1 - i][m - 1 - j] + grid[i][m -
				      1 - j];
				ans += min (cnt, 4 - cnt);
			}
		if (n & 1) {
			for (int j = 0; j <= mr; j++) {
				cnt = grid[nr + 1][j] + grid[nr + 1][m - 1 - j];
				ans += min (cnt, 2 - cnt);
				if (cnt == 1)
					leverage = true;
				if (cnt == 2)
					x++;
			}
		}
		if (m & 1) {
			for (int i = 0; i <= nr; i++) {
				cnt = grid[i][mr + 1] + grid[n - 1 - i][mr + 1];
				ans += min (cnt, 2 - cnt);
				if (cnt == 1)
					leverage = true;
				if (cnt == 2)
					x++;
			}
		}
		return (ans + (((x & 1) and !leverage) << 1) + ((n & 1) and (m & 1)
		        and (grid[nr + 1][mr + 1] == 1)));
	}
};