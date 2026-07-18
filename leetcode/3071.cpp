class Solution {
public:
	int minimumOperationsToWriteY (vector<vector<int>>& grid) {
		int n = grid.size(), ans = 1e9;
		for (int c1 = 0; c1 < 3; c1++)
			for (int c2 = 0; c2 < 3; c2++)
				if (c1 != c2) {
					int toChange = 0;
					for (int i = 0; i < n; i++)
						for (int j = 0; j < n; j++) {
							if (i <= n / 2 and (i == j or i + j == n - 1))
								toChange += grid[i][j] != c1;
							else if (i > n / 2 and (j == n / 2))
								toChange += grid[i][j] != c1;
							else
								toChange += grid[i][j] != c2;
						}
					ans = min (toChange, ans);
				}
		return ans;
	}
};