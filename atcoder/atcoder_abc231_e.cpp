
/**
 * @author      : abhj
 * @created     : Tuesday Dec 14, 2021 12:31:54 IST
 * @filename    : e.cpp
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

int n, x, a[N];
map<pii, int> m;
int f (int x, int pos) {
	if (m.count (mp (x, pos)))
		return m[mp (x, pos)];
	if (pos == n + 1)
		return x == 0 ? 0 : inf;
	if (x % a[pos] == 0)
		return x / a[pos];
	return m[mp (x, pos)] = min ((x / a[pos]) + f (x % a[pos], pos + 1), (x + a[pos] - 1) / a[pos] + f (a[pos] * ((x + a[pos] - 1) / a[pos]) - x, pos + 1));
}

void solve() {
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[n - i - 1];
	cout << f (x, 0);
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
