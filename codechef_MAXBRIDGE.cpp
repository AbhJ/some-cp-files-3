
/**
 * @author      : abhj
 * @created     : Wednesday Nov 17, 2021 23:02:46 IST
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

int n, m;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++)
		cout << i << " " <<  i + 1 << "\n";
	int cnt = m - n + 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j < i - 1; j++) {
			if (cnt-- == 0)
				return;
			cout << j << " " << i << "\n";
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
