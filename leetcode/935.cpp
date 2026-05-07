class Solution {
public:
    int M = 1e9 + 7, dp[10][5001];
    vector<vector<int>> v = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int f (int cur, int n) {
        if (n == 1)
            return 1;
        if (~dp[cur][n])
            return dp[cur][n];
        int ans = 0;
        for (int i = 0; i < v[cur].size(); i++) {
            ans = (f (v[cur][i], n - 1) + ans) % M;
        }
        return dp[cur][n] = ans;
    }
    int knightDialer(int n) {
        memset (dp, - 1, sizeof dp);
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = (f(i, n) + ans) % M;
        }
        return ans;
    }
};