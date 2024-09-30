
/**
 * @author      : abhj
 * @created     : Wednesday Dec 01, 2021 21:53:23 IST
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

int n, h, a[N];

void solve() {
	cin >> n >> h;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int l = 1, r = inf, m;
	function <bool (int)> f = [&] (int k) -> bool {
		int ans = 0;
		for (int i = 1; i < n; i++)
			ans += min (a[i] - a[i - 1], k);
		return ans + k >= h;
	};
	while (l < r) {
		m = l + r >> 1;
		if (f (m))
			r = m;
		else
			l = m + 1;
	}
	cout << r;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
