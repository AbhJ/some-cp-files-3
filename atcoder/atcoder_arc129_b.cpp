/**
 * @author      : abhj
 * @created     : Sunday Nov 21, 2021 23:01:10 IST
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

int n, l[N], r[N], L = - inf, R = inf;

int f (int x) {
	return max ({0LL, x - R, L - x});
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		L = max (L, l[i]);
		R = min (R, r[i]);
		// PROBLEM OCCURS WHEN L > R
		cout << f (L + R >> 1LL) << "\n";
	}
}
int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}

