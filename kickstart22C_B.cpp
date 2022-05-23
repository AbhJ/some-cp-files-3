
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Sunday May 22, 2022 16:46:06 IST
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

int n, x, y;

void solve() {
	cin >> n >> x >> y;
	int sum = n * (n + 1);
	sum /= 2;
	int left = x * sum / (x + y), right = y * sum / (x + y);
	if ((x * sum) % (x + y) != 0 or (y * sum) % (x + y) != 0) {
		cout << "IMPOSSIBLE";
		return;
	}
	set<int>m, l, r;
	for (int i = 1; i <= n; i++)
		m.emplace (i);
	while (m.empty() == 0 and left != 0 and * m.begin() <= left) {
		auto x = m.upper_bound (left);
		x = prev (x);
		left -= *x;
		l.emplace (*x);
		m.erase (x);
	}
	if (left != 0) {
		cout << "IMPOSSIBLE";
		return;
	}
	for (int i : m)
		right -= i;
	if (right == 0) {
		cout << "POSSIBLE\n" << l.size() << "\n";
		for (auto i : l)
			cout << i << " ";
	}
	else
		cout << "IMPOSSIBLE";
}
int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t, x = 0;
	cin >> t;
	while (t--) {
		cout << "Case #" << ++x << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
