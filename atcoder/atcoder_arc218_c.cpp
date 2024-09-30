
/**
 * @author      : abhj
 * @created     : Saturday Nov 20, 2021 16:30:53 IST
 * @filename    : a.cpp
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
const int N    =     1e6 + 10;

int n, m, s, a[N], pre[N];
map<pii, double>dp;

void solve() {
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pre[i] = (i == 0 ? 0 : pre[i - 1]) + a[i];
	}
	function <double (int, int, int)> f = [&] (int n, int m, int s) -> double {
		double ans = 0, tmp = 0;
		int suf = 0;
		if (dp.count (mp (n, s)))
			return dp[mp (n, s)];
		for (int i = n - 1; i > - 1; i--) {
			// TAKING i INTO RIGHT
			suf += a[i];
			tmp = (double) s / (n - i);
			if (tmp > m)
				ans = max (m * suf + f (i, m, s - m * (n - i)), ans);
			else
				ans = max (tmp * suf, ans);
		}
		return dp[mp (n, s)] = ans;
	};
	cout << fixed << setprecision (6) << f (n, m, s);
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
