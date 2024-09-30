
/**
 * @author      : abhj
 * @created     : Sunday Oct 24, 2021 15:45:11 IST
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

int n, a, b, c;

void solve() {
	cin >> a >> b >> c;
	int lef = a + b * 2 + c * 3, rig = 0, dif;
	dif = lef;
	int l = 0, r = a + b + c, m;
	while (r > l) {
		m = l + r >> 1;
		if (m <= a) {
			lef = m;
			rig = a - m + b * 2 + c * 3;
		}
		else if (m <= a + b) {
			lef = a + (m - a) * 2;
			rig = (b - (m - a)) * 2 + c * 3;
		}
		else {
			lef = a + b * 2 + (m - (a + b)) * 3;
			rig = (c - (m - (a + b))) * 3;
		}
		if (dif < abs (lef - rig))
			r = m;
		else
			l = m + 1;
		dif = min (dif, abs (lef - rig));
	}
	if ((a + b * 2 + c * 3) & 1LL)
		dif = min (1LL, dif);
	else
		dif = 0;
	cout << dif;
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
