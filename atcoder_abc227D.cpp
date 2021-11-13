
/**
 * @author      : abhj
 * @created     : Saturday Nov 13, 2021 20:31:09 IST
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

int n, k, a[N];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int l = 0, r = inf / k, m;
	while (r > l) {
		m = (r + l + 1) >> 1;
		int tot = 0;
		for (int i = 0; i < n; i++)
			tot += min (a[i], m);
		if (tot >= m * k)
			l = m;
		else
			r = m - 1;
	}
	cout << l;
}
int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
