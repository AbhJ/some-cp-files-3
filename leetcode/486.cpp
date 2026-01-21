class Solution {
public:
    int winner (vector<int>& nums, int l, int r) {
        int n = nums.size();
        if (l == r)
            return nums[l];
        return max(nums[l] - winner (nums, l + 1, r), nums[r] - winner (nums, l, r - 1));
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return winner (nums, 0, n - 1) >= 0;
    }
};