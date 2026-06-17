class Solution {
public:
    int minSteps (string s, string t) {
        int n = s.length(), ans = 0;
        vector <int> d (26);
        for (int i = 0; i < n; i++) {
            d [s[i] - 'a']++;
            d [t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            ans += (d [i] > 0 ? d[i] : 0);
        }
        return ans;
    }
};