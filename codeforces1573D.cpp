
/**
 * @author      : abhj
 * @created     : Monday Sep 20, 2021 17:59:26 IST
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

int a[N], n, x;

void solve() {
	cin >> n;
	x = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		x ^= a[i];
	}
	if (x != 0) {
		cout << "NO\n";
		return;
	}
	vi v;
	int F = 0;
	for (int i = 1; i <= n; i += 2) {
		// WE FIND A PLACE WHERE PREVIOUSLY IT COULD BE SOLVED
		x ^= a[i] ^ a[i - 1];
		if (x != 0)
			continue;
		F = 1;
		for (int j = 1; j < i; j += 2)
			v.pb (j);
		for (int j = i - 4; j > 0; j -= 2)
			v.pb (j);
		// NOW ONLY THINK OF SUCCESSIVE ELEMENTS
		for (int j = i; j < n - 2; j += 2) {
			v.pb (j + 1);
			v.pb (j);
		}
		break;
	}
	if (F == 0) {
		cout << "NO\n";
		return;
	}
	v.pb (n - 2);
	cout << "YES\n" << v.size() << "\n";
	for (auto i : v)
		cout << i << " ";
	if (v.empty() == 0)
		cout << "\n";
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
