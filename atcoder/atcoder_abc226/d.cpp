
/**
 * @author      : abhj
 * @created     : Tuesday Nov 09, 2021 20:23:44 IST
 * @filename    : d.cpp
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

pii simplify_fraction (int x, int y) {
	int g = __gcd (x, y);
	x /= g, y /= g;
	if (x < 0)
		x = -x, y = -y;
	return mp (x, y);
}

int n, x[N], y[N], X, Y;
set<pii> s;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		for (int j = 0; j < i; j++) {
			X = x[j] - x[i];
			Y = y[j] - y[i];
			s.emplace (simplify_fraction (X, Y));
		}
	}
	cout << ((int)s.size() << 1LL);
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
