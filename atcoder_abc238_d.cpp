
/**
 * @author      : abhj
 * @created     : Saturday Feb 05, 2022 17:50:24 IST
 * @filename    : d.cpp
 */

#include "bits/stdc++.h"
#define int          long long int
#define mp           make_pair
#define pb           emplace_back
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;

int AND, SUM, a, b, XOR;

void solve() {
	cin >> AND >> SUM;
	XOR = SUM - 2 * AND;
	cout << (XOR >= 0 and (AND & XOR) == 0 ? "Yes" : "No");
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
