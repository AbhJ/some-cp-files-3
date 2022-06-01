
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Tuesday May 31, 2022 20:14:48 IST
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
	set < pair<int, int>>s;
	cin >> n;
	vi v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.emplace (a[i], - i - 1);
	}
	for (int i = 0; i < n; i++) {
		if (s.lower_bound (mp (a[i] - 1, 1LL)) == s.end()) {
			cout << - 1;
			return;
		}
		auto it = s.lower_bound (mp (a[i] - 1, 1LL));
		if (- it -> S == i + 1)
			it++;
		if (it == s.end()) {
			cout << - 1;
			return;
		}
		v.pb (- it -> S);
		s.erase (it);
	}
	for (auto i : v)
		cout << i << " ";
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
