class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> m;
        int l = 0, n = s.length(), r, maxSame = 0, ans = min(k, (int)s.length());
        for(r = 0; r < n; r++){
            m[s[r]]++;
            maxSame = max(m[s[r]], maxSame);
            if(r - l + 1 - maxSame > k){
                m[s[l++]]--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};