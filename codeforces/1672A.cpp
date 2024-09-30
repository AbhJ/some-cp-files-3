
/**
 * @author      : abhj
 * @created     : Tuesday May 03, 2022 14:19:06 IST
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

int n, a[N], ans;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i];
	}
	cout << (((ans - n) & 1) ? "errorgorn" : "maomao90");
	ans = 0;
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

