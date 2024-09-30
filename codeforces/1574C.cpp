
/**
 * @author      : abhj
 * @created     : Monday Sep 20, 2021 20:59:34 IST
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

int n, a[N], m, def[N], att[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	sort (a, a + n);
	vi p (n);
	p[0] = a[0];
	for (int i = 1; i < n; i++)
		p[i] = p[i - 1] + a[i];
	for (int i = 0; i < m; i++) {
		cin >> def[i] >> att[i];
		int ind = lower_bound (a, a + n, def[i]) - a;
		if (ind == 0)
			cout << max (0LL, def[i] - a[ind]) +  max (0LL, att[i] - p[n - 1] + a[ind]);
		else if (ind != n)
			cout << min (max (0LL, def[i] - a[ind]) +  max (0LL, att[i] - p[n - 1] + a[ind]), max (0LL, def[i] - a[ind - 1]) +  max (0LL, att[i] - p[n - 1] + a[ind - 1]));
		else
			cout << def[i] - a[ind - 1] + max (0LL, att[i] - p[n - 1] + a[ind - 1]);
		cout << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
