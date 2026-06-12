class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector <vector<long long>> dp (m + 1, vector <long long> (n + 1));
        for (auto v: prices) {
            dp[v[0]][v[1]] = v[2];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int w = 1; w <= j / 2; w++) 
                    dp[i][j] = max (dp[i][w] + dp[i][j - w], dp[i][j]);
                for (int h = 1; h <= i / 2; h++) 
                   dp[i][j] = max (dp[h][j] + dp[i - h][j], dp[i][j]);
            }
        }
        return dp[m][n];
    }
};