class Solution {
public:
    int getMaxLenWithoutZeros (vector<int>& nums) {
        vector <int> posi;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                posi.emplace_back(i);
        }
        if (posi.size() & 1 ^ 1)
            return nums.size();
        return nums.size() - min (posi[0] + 1, (int) nums.size() - posi.back());
    }
    int getMaxLen(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> cur;
        for (auto i: nums) {
            if (i == 0) {
                if (cur.empty())
                    continue;
                v.emplace_back(cur);
                cur.clear();
                continue;
            }
            cur.emplace_back(i);
        }
        if (cur.empty() == 0)
            v.emplace_back(cur);
        int ans = 0;
        for (auto tmp: v) {
            ans = max (getMaxLenWithoutZeros(tmp), ans);
        }
        return ans;
    }
};