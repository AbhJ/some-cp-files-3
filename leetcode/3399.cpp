class Solution {
public:
    bool f (vector <int> &v, int m, int lim) {
        for (int i = 0; i < v.size(); i++) {
            lim -= v[i] / (m + 1);
        }
        return lim >= 0;
    }
    int minLength(string s, int numOps) {
        vector <int> v;
        int n = s.length(), x = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1)
                if (s[i] == '1')
                    c1++;
                else
                    c2++;
            else
                if (s[i] == '1')
                    c2++;
                else
                    c1++;
        }
        if (c1 <= numOps or c2 <= numOps)
            return 1;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n and s[i] == s[j])
                j++;
            v.emplace_back (j - i);
            x = max (j - i, x);
            i = j;
        }
        int l = 2, r = x, m;
        while (l < r) {
            m = (l + r) / 2;
            if (f(v, m, numOps))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
};