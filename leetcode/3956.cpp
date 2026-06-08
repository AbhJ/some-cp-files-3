class Solution {
public:
    vector <long long> pre;
    long long dp[1001][1001], l, r, iniM, n;
    deque <int> d;
    long long f (int i, int m) {
        if (m == 0)
            return 0;
        if (m < 0)
            return - 1e18;
        if (i == n and m == iniM)
            return - 1e18;
        if (i == n)
            return 0;
        if (~dp[i][m])
            return dp[i][m];
        long long ans = - 1e18;
        for (int j = i + l; j <= min(n, i + r); j++) {
            long long su = pre[j - 1] - (i == 0 ? 0 : pre[i - 1]);
            ans = max (su + f(j, m - 1), ans);
        }
        ans = max (f (i + 1, m), ans);
        return dp[i][m] = ans;
    }
    long long h (int i, int j, int m) {
        return (pre[j - 1] + dp [j][m - 1]);
    }
    long long F (int i, int m) {
        if (m == 0)
            return 0;
        if (m < 0)
            return - 1e18;
        if (i == n)
            return - 1e18; 
            
        if (~dp[i][m])
            return dp[i][m];
        int ent = i + l - 1;
        long long ans = F (i + 1, m);
        while (d.empty() == 0 and ent < n and h(i, d.back(), m) < h (i, ent + 1, m)) {
            d.pop_back();
        }
        if (ent < n)
            d.push_back(ent + 1);
        while (d.empty() == 0 and d.front() > i + r)
            d.pop_front();
        if (d.empty() == 0)
            ans = max (h (i, d.front(), m) - (i == 0 ? 0 : pre[i - 1]), ans);
        return dp[i][m] = ans;
    }
    long long maximumSum(vector<int>& v, int m, int ll, int rr) {
        l = ll, r = rr, iniM = m, n = v.size();
        memset (dp, - 1, sizeof dp);
        pre.resize(n);
        for (int i = 0; i < n; i++) {
            pre[i] = v[i] + (i == 0 ? 0 : pre[i - 1]);
        }
        if (n <= 700)
            return f (0, m);
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        long long ans = -1e18;
        for (int k = 1; k <= m; k++) {
            d = deque <int> ();
            ans = max (F (0, k), ans);
        }
        return ans;
    }
};