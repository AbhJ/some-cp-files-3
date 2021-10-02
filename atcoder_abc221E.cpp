
/**
 * @author      : abhj
 * @created     : Saturday Oct 02, 2021 19:27:36 IST
 * @filename    : e.cpp
 */

#include "bits/stdc++.h"
#include "atcoder/all"
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
using namespace atcoder;
const int N    =     2e6 + 10;
using mint = modint998244353;

int n, a[N];

void solve() {
	cin >> n;
	vi v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.pb (a[i]);
	}
	sort (v.begin(), v.end());
	v.erase (unique (v.begin(), v.end()), v.end());
	mint ans = 0;
	int m = v.size();
	fenwick_tree<mint>ft (m);
	for (int i = n - 1; i > - 1; i--) {
		int smaller = lower_bound (v.begin(), v.end(), a[i]) - v.begin();
		ans += ft.sum (smaller, m) * (mint (2).pow (n - 1 - i));
		ft.add (smaller, mint (2).pow (n - i).inv());
	}
	cout << ans.val();
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
