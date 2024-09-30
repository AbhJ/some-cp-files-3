
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Sunday May 29, 2022 23:45:53 IST
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

int n, a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	vi q;
	int r = n / 2, l = 0;
	for (int i = 0; i < n; i++)
		if (i & 1)
			q.pb (a[r++]);
		else
			q.pb (a[l++]);
	for (int i = 0; i < n; i++)
		a[i] = q[i];
	a[n] = a[0];
	for (int i = 1; i < n; i ++) {
		if (a[i] < a[i - 1] and a[i] < a[i + 1])
			continue;
		if (a[i] > a[i - 1] and a[i] > a[i + 1])
			continue;
		cout << "NO";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
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
