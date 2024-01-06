class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        // remove problems in middle
        long long n = nums.size(), first_issue = - 1, last_issue;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                if (first_issue == - 1)
                    first_issue = i;
            }
        }
        if (first_issue == - 1) {
            return n * (n + 1) / 2;
        }
        long long ans = first_issue + 1;
        for (last_issue = n - 1; last_issue == n - 1 or nums[last_issue + 1] > nums[last_issue]; last_issue--) {
            int just_bigger = lower_bound(nums.begin(), nums.begin() + first_issue, nums[last_issue]) - nums.begin();
            ans += just_bigger + 1;
            first_issue = just_bigger;
        }
        return ans;
    }
};