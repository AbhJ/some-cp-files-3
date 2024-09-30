
/**
 * @author      : abhj
 * @created     : Monday Nov 08, 2021 02:47:18 IST
 * @filename    : c.cpp
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
const int N    =     2e6 + 10;

int n, t[N], k[N], dp[N], x;
vi a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> k[i];
		while (k[i]--) {
			cin >> x;
			a[i].pb (x);
		}
	}
	function <int (int)> dfs = [&] (int u) -> int {
		int ans = 0;
		u++;
		while (u--) {
			if (dp[u] == 1) {
				ans += t[u];
				for (auto i : a[u])
					dp[i] = 1;
			}
		}
		return ans;
	};
	dp[n] = 1;
	cout << dfs (n);
}
int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
