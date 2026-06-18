class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        map <int, int> dp;
        dp[0] = 0;
        for (int i: nums) if (i) {
            target ^= i;
            for (auto [x, si]: dp) {
                if (dp.count(x ^ i) == 0)
                    dp[x ^ i] = 1 + si;
                else
                    dp[x ^ i] = min (1 + si, dp[x ^ i]);
            }
        }
        if (dp.count(target) == 0)
            return - 1;
        return dp[target];
    }
};