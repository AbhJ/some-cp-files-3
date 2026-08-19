class Solution {
public:
    int ans, n, m;
    long long cnt;
    vector <int> dx {0, - 1, 0, 1}, dy {- 1, 0, 1, 0};
    void bfs (vector<vector<int>>& grid, int x, int y, int col) {
        if (grid[x][y] <= 0)
            return;
        cnt += grid[x][y];
        grid[x][y] = col;
        for (int k = 0; k < 4; k++) {
            int X = x + dx[k], Y = y + dy[k];
            if (X > n - 1 or Y > m - 1 or X < 0 or Y < 0)
                continue;
            bfs (grid, X, Y, col);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int col = - 1;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    bfs (grid, i, j, col--);
                    if (cnt % k == 0)
                        ans++;
                    cnt = 0;
                }
            }
        return ans;
    }
};