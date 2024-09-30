
/**
 * @author      : abhj
 * @created     : Saturday Jan 29, 2022 17:45:45 IST
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
const int N    =     2e6 + 10;

int n, l, w, a[N], ans;
vpii v;

void solve() {
	cin >> n >> l >> w;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int prev = (i == 0 ? 0 : a[i - 1] + w);
		ans += (a[i] - prev + w - 1) / w;
	}
	ans += (l - (a[n - 1] + w) + w - 1) / w;
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
