class Solution {
public:
    bool check (vector<int>& nums, int l, int r, int& target, int n){
        if (n == 1)
            return nums[0] == target;
        if (l < 0 or r > n - 1 or l > n - 1 or r < 0)
            return false;
        int m;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }
        return nums[r] == target;
    }
    bool isPresent(vector<int>& nums, int target) {
        for (auto &i: nums)
            if(i == target)
                return true;
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int l = 0, n = nums.size(), r = n - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] <= nums[r])
                r = m;
            else
                l = m + 1;
        }
        return check (nums, 0, r - 1, target, n) or check (nums, r, n - 1, target, n) or isPresent (nums, target);
    }
};