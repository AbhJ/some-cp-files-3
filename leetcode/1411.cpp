class Solution {
public:
	long long int dp[5001][4][4][4], nn;
	long long f(int x, int a, int b, int c) {
		if (x == nn)
			return 1;
		if (~dp[x][a + 1][b + 1][c + 1])
			return dp[x][a + 1][b + 1][c + 1];
		long long int &cnt = dp[x][a + 1][b + 1][c + 1] = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)if (j != i)
					for (int k = 0; k < 3; k++)if (k != j)
							if (i != a and j != b and k != c)
								cnt += f(x + 1, i, j, k),
								       cnt %= (long long int) (1e9 + 7);
		return cnt;
	}
	int numOfWays(int n) {
		memset(dp, - 1LL, sizeof dp); nn = n;
		return ((int)f(0, - 1, - 1, - 1));
	}
};