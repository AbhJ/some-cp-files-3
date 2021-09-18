
/**
 * @author      : abhj
 * @created     : Saturday Sep 18, 2021 17:52:34 IST
 * @filename    : d.cpp
 */

#include "bits/stdc++.h"
#define int          long long int
#define mp           make_pair
#define pb           emplace_back
#define F            first
#define S            second
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     610;

int n, x, y, a[N], b[N];

void solve() {
	cin >> n >> x >> y;
	vvi dp (N, vi (N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		auto dptmp = dp;
		for (int j = 0; j <= x; j++) {
			for (int k = 0; k <= y; k++) {
				dptmp[min (j + a[i], x)][min (k + b[i], y)] = min (
							1 + dp[j][k],
							dptmp[min (j + a[i], x)][min (k + b[i], y)]
						);
			}
		}
		swap (dptmp, dp);
	}
	int cost = dp[x][y];
	cout << (cost == inf ? - 1 : cost);
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
