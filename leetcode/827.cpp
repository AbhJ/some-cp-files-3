class Solution {
public:
	vector <int> cntCol, dx {-1, 0, 1, 0}, dy {0, 1, 0, -1};
	int ans;
	void dfs (vector<vector<int>>& grid, int x, int y, int col) {
		int n = grid.size(), m = grid[0].size();
		grid[x][y] = col;
		cntCol[col]++;
		ans = max (ans, cntCol[col]);
		for (int k = 0; k < 4; k++) {
			int X = dx[k] + x, Y = dy[k] + y;
			if (X < 0 or Y < 0 or X > n - 1 or Y > m - 1 or grid[X][Y] != 1)
				continue;
			dfs (grid, X, Y, col);
		}
	}
	int largestIsland (vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size(), curCol = 2;
		cntCol.resize (n * m + 2);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1)
					dfs (grid, i, j, curCol++);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) {
					int tmp = 1;
					set <int> s;
					for (int k = 0; k < 4; k++) {
						int X = i + dx[k], Y = j + dy[k];
						if (X < 0 or Y < 0 or X > n - 1 or Y > m - 1)
							continue;
						s.emplace (grid[X][Y]);
					}
					for (auto i : s)
						tmp += cntCol [i];
					ans = max (tmp, ans);
				}
			}
		}
		cout << cntCol[2];
		return ans;
	}
};