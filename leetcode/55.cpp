class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), isP = 0;
        for (int i = 0; i < n; i++) {
            if (isP < i)
                return false;
            isP = max (min(nums[i] + i, n - 1), isP);
        }
        return true;
    }
};