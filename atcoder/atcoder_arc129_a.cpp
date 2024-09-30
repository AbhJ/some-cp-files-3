
/**
 * @author      : abhj
 * @created     : Sunday Nov 21, 2021 17:36:37 IST
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

int n, l, r;

void solve() {
	cin >> n >> l >> r;
	int j = log2 (n), ans = 0;
	function <void (int)> f = [&] (int j) -> void {
		if (j < 0)
			return;
		if ((n >> j) & 1LL)
			ans += max (0LL, min (((1LL << (j + 1)) - 1LL), r) - max ((1LL << j), l) + 1LL);
		f (j - 1);
	};
	f (j);
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
