
/**
 * @author      : abhj
 * @created     : Saturday Nov 20, 2021 17:50:26 IST
 * @filename    : c.cpp
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

int n, k, p[N][3], su[N], s[N];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> p[i][j];
			su[i] += p[i][j];
		}
	}
	copy (su, su + n, s);
	sort (su, su + n, greater<int>());
	int val = su[k - 1];
	for (int i = 0; i < n; i++) {
		if (s[i] >= val - 300)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
