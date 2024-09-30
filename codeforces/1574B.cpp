
/**
 * @author      : abhj
 * @created     : Monday Sep 20, 2021 20:40:36 IST
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

int m;
vector<int> v (3);

void solve() {
	cin >> v[0LL] >> v[1] >> v[2] >> m;
	sort (v.begin(), v.end());
	int cnt = max (0LL, v[0LL] - 1) + max (0LL, v[1] - 1) + max (0LL, v[2] - 1);
	cout << (cnt >= m and v[2] - v[1] - v[0] - 1 <= m ? "YES" : "NO");
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0LL);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0LL;
}
