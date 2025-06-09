class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), cnt = 0;
        for (long long mask = 0; mask < (1LL << n); mask++) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1LL << i))
                    tmp += nums[i];
                else
                    tmp -= nums[i];
            }
            cnt += target == tmp;
        }
        return cnt;
    }
};