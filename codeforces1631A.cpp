
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Thursday May 19, 2022 11:40:51 IST
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

int n, a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int maxa = - inf, maxb = - inf;
	for (int i = 0; i < n; i++) {
		int ma = max (a[i], b[i]);
		int mi = min (a[i], b[i]);
		maxa = max (maxa, ma);
		maxb = max (maxb, mi);
	}
	cout << maxa * maxb;
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
