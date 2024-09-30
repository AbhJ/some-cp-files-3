
/**
 * @author      : abhj
 * @created     : Monday Apr 25, 2022 18:31:13 IST
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

int n, x, a[N], b[N], tot, cnt;

void solve() {
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	cnt = accumulate (a, a + n, 0LL);
	for (int i = n - 1; ~i; i--) {
		if (x - cnt < 0)
			b[i] = - 1;
		else
			b[i] = max (0LL, (x - cnt) / (i + 1));
		tot += (b[i] - (i == n - 1 ? - 1 : b[i + 1])) * (i + 1);
		cnt -= a[i];
	}
	cout << tot;
	tot = cnt = 0;
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
