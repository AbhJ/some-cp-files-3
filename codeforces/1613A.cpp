
/**
 * @author      : abhj
 * @created     : Wednesday Dec 01, 2021 20:08:45 IST
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

int x1, p1, x2, p2;

void solve() {
	cin >> x1 >> p1 >> x2 >> p2;
	while (x1 % 10 == 0)
		x1 /= 10, p1++;
	while (x2 % 10 == 0)
		x2 /= 10, p2++;
	if (p1 + ceil ((int)log10 (x1)) < p2 + ceil ((int)log10 (x2)))
		cout << '<';
	else if (p1 + ceil ((int)log10 (x1)) > p2 + ceil ((int)log10 (x2)))
		cout << '>';
	else {
		if (p1 < p2)
			x2 *= pow (10, p2 - p1);
		if (p2 < p1)
			x1 *= pow (10, p1 - p2);
		if (x1 < x2)
			cout << '<';
		else if (x2 < x1)
			cout << '>';
		else
			cout << '=';
	}
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
