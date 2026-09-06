class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int total_len = nums.size();
        int n = total_len / 2;
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> left_sums(n + 1), right_sums(n + 1);
        for (int mask = 0; mask < (1 << n); ++mask) {
            int k = __builtin_popcount(mask);
            int l_sum = 0, r_sum = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    l_sum += nums[i];
                    r_sum += nums[i + n];
                }
            }
            left_sums[k].push_back(l_sum);
            right_sums[k].push_back(r_sum);
        }
        for (int k = 0; k <= n; ++k) {
            sort(right_sums[k].begin(), right_sums[k].end());
        }

        int ans = abs(total_sum - 2 * left_sums[n][0]); 

        for (int k = 1; k < n; ++k) {
            for (int x : left_sums[k]) {
                int target = total_sum / 2 - x;
                auto& right_list = right_sums[n - k];
                
                auto it = lower_bound(right_list.begin(), right_list.end(), target);

                if (it != right_list.end()) {
                    ans = min(ans, abs(total_sum - 2 * (x + *it)));
                }
                if (it != right_list.begin()) {
                    ans = min(ans, abs(total_sum - 2 * (x + *prev(it))));
                }
            }
        }
        return ans;
    }
};