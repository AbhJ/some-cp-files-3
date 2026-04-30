class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int K) {
        int n = a.size();
        vector <int> dp(n);
        for (int i = 0; i < n; i++) {
            int ma = a[i];
            for (int k = 0; k < K and i - k >= 0; k++) {
                ma = max (a[i - k], ma);
                dp[i] = max ((i - k == 0 ? 0 : dp[i - k - 1]) + ma * (k + 1), dp[i]);
            }
        }
        return dp.back();
    }
};