
/**
 * @author      : abhj
 * @created     : Wednesday Dec 29, 2021 11:47:33 IST
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

int n, k, a, s, ans;
map<int, int>m;

void solve() {
	cin >> n >> k;
	m[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s += a;
		ans += m[s - k];
		m[s]++;
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
