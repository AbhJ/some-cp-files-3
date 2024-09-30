
/**
 * @author      : abhj
 * @created     : Saturday Nov 20, 2021 17:35:54 IST
 * @filename    : b.cpp
 */

#include "bits/stdc++.h"
// #include "atcoder/all"
// #define int          long long int
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
// using namespace atcoder;
// const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;

int n, a[N], x, vis[N];

void solve() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vis[x] = 1;
	function <void (int)> f = [&] (int i) -> void {
		if (vis[a[i]])
			return;
		vis[a[i]] = 1;
		f (a[i]);
	};
	f (x);
	cout << count (vis, vis + 1 + n, 1);
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
