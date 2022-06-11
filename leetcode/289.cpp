class Solution {
public:
	int dx[8] = {1, 0, -1, 0, -1, 1, 1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
	void gameOfLife (vector<vector<int>> &a) {
		//2 means now living prev dead
		//3 means now dead prev living
		int n = a.size(), m = a[0].size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int x = i + dx[k], y = j + dy[k];
					if (x<0 or x >= n or y<0 or y >= m)
						continue;
					if (a[x][y] & 1)
						cnt++;
				}
				int x = i, y = j;
				if (cnt < 2) {
					if (a[x][y] == 0)
						a[x][y] = 0;
					else
						a[x][y] = 3;
				}
				else if (cnt > 3) {
					if (a[x][y] == 0)
						a[x][y] = 0;
					else
						a[x][y] = 3;
				}
				else if (cnt == 3) {
					if (a[x][y] == 0)
						a[x][y] = 2;
				}
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] == 2)
					a[i][j] = 1;
				else if (a[i][j] == 3)
					a[i][j] = 0;
	}
};
