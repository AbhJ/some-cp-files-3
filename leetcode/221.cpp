class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        int n = v.size(), m = v[0].size(), ans = 0, r;
        vector<vector<int>> a (n, vector <int> (m)), l (n, vector <int> (m, - 1));
        for (int i = 0; i < n; i++) {
            stack <int> s;
            for (int j = 0; j < m; j++) {
                a[i][j] = (v[i][j] - '0') + ((v[i][j] == '1' and i != 0) ? a[i - 1][j] : 0);
                while (s.empty() == 0 and a[i][s.top()] >= a[i][j])
                    s.pop();
                if (s.empty() == 0)
                    l[i][j] = s.top();
                s.emplace(j);
            }
            s = stack <int> ();
            for (int j = m - 1; ~j; j--) {
                while (s.empty() == 0 and a[i][s.top()] >= a[i][j])
                    s.pop();
                r = m;
                if (s.empty() == 0)
                    r = s.top();
                ans = max (min((r - l[i][j] - 1), a[i][j]) * min((r - l[i][j] - 1), a[i][j]), ans);
                s.emplace(j);
            }
        }
        return ans;
    }
};