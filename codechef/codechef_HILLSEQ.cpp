
/**
 * @author      : abhj
 * @created     : Wednesday Nov 17, 2021 18:08:35 IST
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

int n, a[N], poss, F;
map<int, int>m;

void hill() {
	vi l, r;
	for (int i = 1; i < n; i++) {
		if (r.empty() or (r.back() != a[i])) {
			r.pb (a[i]);
			continue;
		}
		if (l.empty() or (l.back() != a[i])) {
			l.pb (a[i]);
			continue;
		}
		cout << - 1;
		return;
	}
	if ((l.empty() == 0 and l[0] == a[0]) or (r.empty() == 0 and r[0] == a[0])) {
		cout << - 1;
		return;
	}
	reverse (l.begin(), l.end());
	for (auto i : l)
		cout << i << " ";
	cout << a[0] << " ";
	for (auto i : r)
		cout << i << " ";
}

void solve() {
	cin >> n;
	F = 0, poss = 0;
	m.clear();
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
		if (m[a[i]] > 1)
			F = 1;
		if (m[a[i]] > 2)
			poss = 1;
	}
	if (poss) {
		cout << - 1;
		return;
	}
	sort (a, a + n, greater<int>());
	if (!F) {
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		return;
	}
	hill();
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
