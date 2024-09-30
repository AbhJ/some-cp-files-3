
/**
 * @author      : abhj
 * @created     : Sunday Oct 03, 2021 20:08:52 IST
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

int n, a[N], h;

void solve() {
	cin >> n >> h;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n, greater<int>());
	if (h <= a[0])
		cout << 1;
	else {
		int tmp = a[0] + a[1];
		int ans = 2 * (h / tmp);
		if (h % tmp == 0)
			cout << ans;
		else if ((h % tmp) <= a[0])
			cout << ans + 1;
		else
			cout << ans + 2;
	}
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
