class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map <int, int> m;
        int ans = 1;
        for (auto i: arr) {
            if (m.count(i - difference) == 0) {
                m[i] = 1;
                continue;
            }
            m[i] = max ({1, m[i], m[i - difference] + 1});
            ans = max (ans, m[i]);
        }
        return ans;
    }
};