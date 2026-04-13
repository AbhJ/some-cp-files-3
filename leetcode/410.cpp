class Solution {
public:
    bool f (vector<int>& nums, int k, int su) {
        int cu = 0, sp = 1;
        for (auto i: nums) {
            if (cu + i <= su) {
                cu += i;
                continue;
            }
            if (cu > su)
                return false;
            cu = i;
            sp++;
        }
        if (su == 1)  
            cout << sp;
        return sp <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = accumulate (nums.begin(), nums.end(), 0), m;
        while (l < r) {
            m = ((l + r) >> 1);
            if (f(nums, k, m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
};