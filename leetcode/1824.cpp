class Solution {
public:
    vector <vector<int>> dp;
    int n, ans;
    int minSideJumps (vector<int>& obstacles) {
        n = obstacles.size() - 1;
        dp = vector <vector<int>> (n + 1, vector <int> (4));
        dp[0][1] = dp[0][3] = 1;
        for (int i = 1; i <= n; i++)
            for (int r = 1; r <= 3; r++) {
                dp[i][r] = 1e9;
                for (int lr = 1; lr <= 3; lr++) {
                    if (obstacles[i - 1] != r and obstacles[i] != r)
                        dp[i][r] = min (dp[i - 1][lr] + (lr != r), dp[i][r]);
                }
            }
        return min ({dp[n][1], dp[n][2], dp[n][3]});
    }
};