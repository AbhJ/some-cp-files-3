
/**
 * @author      : abhj
 * @created     : Saturday Feb 05, 2022 17:37:23 IST
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

int n, a[N], tmp;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
		a[i] %= 360;
	}
	a[n] = 360;
	sort (a, a + n + 1);
	tmp = a[0];
	for (int i = 0; i <= n; i++)
		tmp = max (tmp, a[i] - (i == 0 ? a[n] : a[i - 1]));
	cout << tmp;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
