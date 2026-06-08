class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; i++) {
            string t = bitset<32>(i).to_string();
            t.erase(0, t.find_first_not_of('0'));
            if (!s.contains(t)) 
                return false;
        }
        return true;
    }
};