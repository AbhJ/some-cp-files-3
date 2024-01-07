class Solution {
public:
    int n, m;
    vector<pair<int, int>> dir {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    void dfs (int x, int y, vector<vector<char>>& grid) {
        for (auto [dx, dy]: dir){
            int X = x + dx, Y = y + dy;
            if (X < 0 or Y < 0 or X >= n or Y >= m or grid[X][Y] != '1')
                continue;
            grid[X][Y] = '0';
            dfs(X, Y, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    grid[i][j] = '0';
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};