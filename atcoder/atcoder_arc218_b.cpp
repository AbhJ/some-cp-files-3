
/**
 * @author      : abhj
 * @created     : Friday Nov 19, 2021 12:21:48 IST
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

vi a (3);

void solve() {
	cin >> a[0] >> a[1] >> a[2];
	sort (a.begin(), a.end());
	if ((a[1] - a[0]) % 3 == 0)
		cout << a[1];
	else if ((a[2] - a[0]) % 3 == 0 or (a[2] - a[1]) % 3 == 0)
		cout << a[2];
	else
		cout << - 1;
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
