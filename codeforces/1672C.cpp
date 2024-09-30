
/**
 * @author      : abhj
 * @created     : Wednesday May 04, 2022 10:35:10 IST
 * @filename    : c.cpp
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

int n, a[N];
void solve() {
	cin >> n;
	vi v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0 and a[i] == a[i - 1])
			v.pb (i);
	}
	if (v.empty()) {
		cout << 0;
		return;
	}
	if (v.back() == v.front() + 1) {
		assert (v.size() == 2);
		cout << 1;
		return;
	}
	cout << max (0LL, v.back() - v.front() - 1LL);
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
