class Solution {
public:
    int ans(string& s, map<pair<int, int>, int> &dp, int l, int r, int k){
        if(r - l + 1 < k)
            return dp[make_pair(l, r)] = 0;
        vector<int>cnt(26);
        for(int i = l; i <= r; i++)
            cnt[s[i] - 'a']++;
        if(dp.count(make_pair(l, r)))
            return dp[make_pair(l, r)];
        for(int i = l; i <= r; i++)
            if(cnt[s[i] - 'a'] < k){
                int j = i;
                while(j != r and cnt[s[j] - 'a'] < k)
                    j++;
                dp[make_pair(l, r)] = max({dp[make_pair(l, r)], 
                    ans(s, dp, l, i - 1, k),
                    ans(s, dp, j, r, k)});
                break;
            } 
            if(!dp.count(make_pair(l, r)))
                dp[make_pair(l, r)] = r - l + 1;
            return dp[make_pair(l, r)];
        }
        int longestSubstring(string s, int k) {
            map<pair<int, int>, int> dp;
            return ans(s, dp, 0, s.length() - 1, k);
        }
    };