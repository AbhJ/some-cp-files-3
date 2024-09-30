
/**
 * @author      : abhj
 * @created     : Monday Dec 06, 2021 20:53:30 IST
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

int n, d, cov, cnt;
pii a[N];

void solve() {
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		cin >> a[i].S >> a[i].F;
	sort (a, a + n);
	for (int i = 0; i < n; i++) {
		int end = a[i].F, sta = a[i].S;
		if (cov < sta)
			cov = end + d - 1, cnt++;
	}
	cout << cnt;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
