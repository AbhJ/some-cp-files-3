

/**
 * @author      : abhj
 * @created     : Sunday Sep 19, 2021 02:00:00 IST
 * @filename    : b.cpp
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

int n, a[N], b[N], pos[N], co, tmp;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		pos[b[i]] = i;
	}
	for (int i = 2 * n; i > 0; i -= 2)
		pos[i - 2] = min (pos[i - 2], pos[i]);
	co = inf;
	for (int i = 0; i < n; i++)
		co = min (co, i + pos[a[i] + 1]);
	cout << co;
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
