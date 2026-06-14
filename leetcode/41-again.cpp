class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool isOne = false;
        for (int &i: nums) {
            if (i == 1)
                isOne = true;
            if (i > nums.size() or i <= 0)
                i = 1;
        }
        if (isOne == false)
            return 1;
        for (int i: nums) 
            nums[abs(i) - 1] = - abs(nums[abs(i) - 1]);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                continue;
            return i + 1;
        }
        return nums.size() + 1;
    }
};