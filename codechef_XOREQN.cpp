
/**
 * @author      : abhj
 * @created     : Tuesday Nov 16, 2021 20:28:46 IST
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
const int inf  =     2e18 + 10;
const int N    =     2e6 + 10;

int n, a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for (int j = 0; j < 65; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cnt ^= ((a[i] >> j) & 1LL);
		if (cnt) {
			for (int i = 0; i < n; i++) {
				if (a[i] >= inf - (1LL << j)) {
					cout << - 1;
					return;
				}
				a[i] += (1LL << j);
			}
			ans |= (1LL << j);
		}
	}
	int x = 0;
	for (int i = 0; i < n; i++)
		x ^= a[i];
	cout << (x ? - 1 : ans);
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
