
/**
 * @author      : abhj
 * @created     : Sunday Sep 19, 2021 18:39:43 IST
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

int a, b, c;

void solve() {
	cin >> a >> b >> c;
	int x, cnt = 0;
	x = min (b / 2, c);
	cnt += x;
	b -= 2 * x, c -= x;
	x = min (a, b) / 2;
	cnt += x;
	a -= 2 * x, b -= 2 * x;
	x = min (c / 2, a);
	cnt += x;
	a -= x, c -= 2 * x;
	x = min (a / 3, c);
	cnt += x;
	a -= 3 * x, c -= x;
	x = min (a / 5, inf);
	cnt += x;
	a -= 5 * x;
	cout << cnt;
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
