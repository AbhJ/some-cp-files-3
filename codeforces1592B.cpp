
/**
 * @author      : abhj
 * @created     : Sunday Oct 03, 2021 20:17:02 IST
 * @filename    : b.cpp
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

int n, a[N], k;

void solve() {
	cin >> n >> k;
	vi v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.pb (a[i]);
	}
	sort (v.begin(), v.end());
	for (int i = n - k; i < k; i++) {
		if (v[i] != a[i]) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
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
