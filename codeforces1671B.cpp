
/**
 * @author      : abhj
 * @created     : Sunday Apr 24, 2022 14:34:37 IST
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

int n, a[N];

void solve() {
	int cnt = 0;
	cin >> n;
	for (int i = 0;  i < n; i ++)
		cin >> a[i];
	cnt = a[n - 1] - a[0] - n;
	cout << (cnt <= 1 ? "YES" : "NO");
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

