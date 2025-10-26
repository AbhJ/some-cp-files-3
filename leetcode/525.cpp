class Solution {
public:
    int findMaxLength (vector<int>& nums) {
        int n = nums.size(), ans = 0, pre = 0;
        map <int, int> m;
        m[0] = - 1;
        for (int i = 0; i < n; i++) {
            pre += (nums[i] ? 1 : - 1);
            if (m.count (pre) == 0)
                m[pre] = i;
            else
                ans = max (i - m[pre], ans);
        }
        return ans;
    }
};