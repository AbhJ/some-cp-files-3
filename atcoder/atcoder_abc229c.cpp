/**
 * @author      : abhj
 * @created     : Saturday Nov 27, 2021 18:03:14 IST
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

int n, w, a[N], b[N];
static bool cmp (int A, int B) {
	return a[A] > a[B];
}

void solve() {
	cin >> n >> w;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	vi num (n);
	iota (num.begin(), num.end(), 0);
	sort (num.begin(), num.end(), cmp);
	int ans = 0;
	for (auto i : num) {
		ans += a[i] * min (w, b[i]);
		w -= min (w, b[i]);
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}

