
/**
 * @author      : abhj
 * @created     : Sunday Oct 24, 2021 15:52:36 IST
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
	cin >> n;
	int ones = 0, zeros = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1)
			ones++;
		if (a[i] == 0)
			zeros++;
	}
	cout << ones * (1LL << zeros);
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
