class Solution {
public:
    int dp [201][201];
    int f (int l, int r) {
        if (l >= r)
            return 0;
        if (dp[l][r] != 1e9)
            return dp[l][r];
        for (int i = l; i <= r; i++) {
            dp[l][r] = min (i + max(f(l, i - 1), f(i + 1, r)), dp[l][r]);
        }
        return dp[l][r];
    }
    int getMoneyAmount(int n) {
        fill (&dp[0][0], &dp[0][0] + 201 * 201, 1e9);
        return f (1, n);
    }
};