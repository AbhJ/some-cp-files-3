
/**
 * @author      : abhj
 * @created     : Wednesday Dec 01, 2021 20:31:09 IST
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

set<int> s;
int a[N], n;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], s.emplace (a[i]);
	sort (a, a + n);
	set<pii> v;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (s.count (a[j] % a[i]) == 0) {
				v.emplace (a[j], a[i]);
				if (v.size() == n / 2) {
					for (auto k : v)
						cout << k.F << " " << k.S << "\n";
					s.clear();
					return;
				}
			}
		}
	}
	assert (0);
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
