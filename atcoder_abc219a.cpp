
/**
 * @author      : abhj
 * @created     : Saturday Sep 18, 2021 17:33:48 IST
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

int x;

void solve() {
	cin >> x;
	if ( x >= 90)
		cout << "expert";
	else if (x >= 70)
		cout << 90 - x;
	else if (x >= 40)
		cout << 70 - x;
	else
		cout << 40 - x;
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
