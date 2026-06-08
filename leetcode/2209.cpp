class Solution {
public:
    string s;
    int n, len, pre[1001], dp[1001][1001];
    int f (int i, int cur) {
        if (cur < 0)
            return 1e9;
        if (i >= n)
            return 0;
        if (~dp[i][cur]) 
            return dp[i][cur];
        return dp[i][cur] = min (f (i + len, cur - 1), (s[i] - '0') + f(i + 1, cur));
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        s = floor;
        n = s.length();
        len = carpetLen;
        memset (dp, - 1, sizeof dp);
        return f (0, numCarpets);
    }
};