class Solution {
public:
    static bool cmp (string s, string t) {
        return s + t > t + s;
    }
    string cleanup (string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0')
                continue;
            return s.substr (i);
        }
        return "0";
    }
    string largestNumber (vector<int>& nums) {
        vector <string> v;
        for (auto i : nums)
            v.emplace_back (to_string (i));
        sort (v.begin(), v.end(), cmp);
        string s;
        for (string tmp : v)
            s += tmp;
        return cleanup (s);
    }
};