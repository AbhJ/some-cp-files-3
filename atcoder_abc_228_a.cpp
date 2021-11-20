
/**
 * @author      : abhj
 * @created     : Saturday Nov 20, 2021 17:31:18 IST
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

int s, t, x;

void solve() {
	cin >> s >> t >> x;
	if (t < s)
		t += 24;
	if (x < s)
		x += 24;
	cout << ((x >= s and t > x) ? "Yes" : "No");
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
