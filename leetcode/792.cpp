class Solution {
public:
    int numMatchingSubseq (string s, vector<string>& words) {
        vector <int> pos [26];
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
            pos[s[i] - 'a'].emplace_back (i);
        for (auto word : words) {
            int las = - 1;
            bool nope = false;
            for (auto c : word) {
                auto lasIt = upper_bound (pos[c - 'a'].begin(), pos[c - 'a'].end(), las);
                if (lasIt == pos[c - 'a'].end()) {
                    nope = true;
                    break;
                }
                las = * lasIt;
            }
            cnt += !nope;
        }
        return cnt;
    }
};