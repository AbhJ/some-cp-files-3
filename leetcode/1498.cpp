class Solution {
public:
    int powM (long long b, long long p) {
        long long r = 1;
        for (; p; b = b * b % (int) (1e9 + 7), p /= 2)
            if (p & 1)
                r = r * b % (int) (1e9 + 7);
        return r;
    }
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        sort (nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            auto secPos = upper_bound (nums.begin() + i, nums.end(), target - nums[i]);
            if (secPos == nums.begin() + i)
                break;
            if (*(prev(secPos)) + nums[i] <= target)
                ans += powM(2, secPos - nums.begin() - i - 1);
            ans = ans % (int) (1e9 + 7);
        }
        return ans;
    }
};