class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector <bool> vis (nums.size());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0, tmp = i;
            while (vis [tmp] == 0) {
                vis[tmp] = 1;
                tmp = nums[tmp];
                ans = max (++cnt, ans);
            }
        }
        return ans;
    }
};