class Solution {
public:
    int N = 1e5, sz;
    int m[(int) 1e5 + 1];
    vector <int> v[(int) 1e5 + 1];
    void f () {
        for (int i = 2; i <= N; i++) if (v[i].empty()){
            for (int j = i; j <= N; j += i)
                v[j].emplace_back(i);
            }
        }
    void rem (int x) {
        for (auto i: v[x]) {
            if (--m[i] == 0)
                sz--;
        }
    }
    void ins (int x) {
        for (auto i: v[x]) {
            if (m[i] == 0)
                sz++;
            m[i]++;
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, l = 0;
        N = *max_element (nums.begin(), nums.end());
        f ();
        for (int r = 0; r < n; r++) {
            ins (nums[r]);
            while (sz > k and l <= r) {
                rem(nums[l++]);
            }
            ans = max (ans, r - l + 1);
        }
        return ans;
    }
};