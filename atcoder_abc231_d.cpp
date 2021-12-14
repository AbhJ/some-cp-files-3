
/**
 * @author      : abhj
 * @created     : Tuesday Dec 14, 2021 10:44:04 IST
 * @filename    : d.cpp
 */

#include "bits/stdc++.h"
#include "atcoder/all"
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
using namespace atcoder;
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;

int n, m, a[N], b[N], koi[N];
pii e[N];

void solve() {
	cin >> n >> m;
	dsu d (n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		e[i] = mp (a[i], b[i]);
		koi[a[i]]++;
		koi[b[i]]++;
		if (koi[a[i]] > 2 or koi[b[i]] > 2 or d.same (a[i], b[i])) {
			cout << "No";
			return;
		}
		d.merge (a[i], b[i]);
	}
	cout << "Yes";
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
