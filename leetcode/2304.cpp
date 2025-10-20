class Solution {
public:
    vector <vector<int>> dp, a, c;
    int n, m;
    int dfs (int x, int y) {
        if (x == n - 1)
            return a[x][y];
        if (~dp[x + 1][y])
            return dp[x + 1][y];
        int ans = 1e9;
        for (int j = 0; j < m; j++) {
            if (x != - 1)
                ans = min (a[x][y] + dfs (x + 1, j) + c[a[x][y]][j], ans);
            else
                ans = min (dfs (x + 1, j), ans);
        }
        return dp[x + 1][y] = ans;
    }
    int minPathCost (vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        n = grid.size(), m = grid[0].size();
        dp = vector<vector<int>> (n + 1, vector <int> (m, - 1));
        a = grid, c = moveCost;
        return dfs (- 1, 0);
    }
};