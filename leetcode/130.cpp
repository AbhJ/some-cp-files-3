class Solution {
public:
	int n, m;
	int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
	void dfs (int i, int j, vector<vector<char>> &A) {
		if (A[i][j] != 'O')
			return;
		A[i][j] = 'Z';
		for (int k = 0; k < 4; k++) {
			int x = i + dx[k], y = j + dy[k];
			if (x<0 or y<0 or x >= n or y >= m)
				continue;
			dfs (x, y, A);
		}
	}

	void solve (vector<vector<char>> &A) {
		n = A.size(), m = A[0].size();
		for (int i = 0; i < n; i++) {
			dfs (i, 0, A);
			dfs (i, m - 1, A);
		}
		for (int i = 1; i < m - 1; i++) {
			dfs (0, i, A);
			dfs (n - 1, i, A);
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (A[x][y] == 'Z')
					A[x][y] = 'O';
				else
					A[x][y] = 'X';
			}
		}
	}
};
