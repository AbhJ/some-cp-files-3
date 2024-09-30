
/**
 * @author      : abhj
 * @created     : Thursday May 05, 2022 10:38:35 IST
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

int n, a[N], b[N];
multiset<int> s;
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[j]) {
			j++;
			continue;
		}
		if (i != 0 and (a[i - 1] == b[j] and s.count (b[j]))) {
			s.erase (s.find (b[j++]));
			i--;
			continue;
		}
		s.emplace (a[i]);
	}
	while (a[n - 1] == b[j] and s.count (b[j]))
		s.erase (s.find (b[j++]));
	s.clear();
	cout << (j == n ? "YES" : "NO");
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
