class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n3 != n1 + n2)
            return false;
        bool dp [n1 + 1][n2 + 1];
        memset (dp, false, sizeof dp);
        dp[0][0] = true;
        for (int i2 = 0; i2 <= n2; i2 ++){
            for (int i1 = 0; i1 <= n1; i1 ++){
                int i3 = i1 + i2;
                if (s1[i1] == s3[i3] and i1 != n1)
                    dp[i1 + 1][i2] |= dp[i1][i2];
                if (s2[i2] == s3[i3] and i2 != n2)
                    dp[i1][i2 + 1] |= dp[i1][i2];
            }
        }
        return dp[n1][n2];
    }
};
