/**
 * @author      : abhj
 * @created     : Sunday Oct 03, 2021 20:27:40 IST
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

int n, ans, A[N], F, k;
map<int, int>m;
vvi a;

int dfs (int u, int p = - 1) {
	int x = 0;
	for (auto i : a[u])
		if (i != p)
			x ^= dfs (i, u);
	x ^= A[u];
	m[x]++;
	return x;
}

void solve() {
	cin >> n >> k;
	F = 0;
	m.clear();
	for (int i = 0; i < n; i++)
		cin >> A[i];
	a.clear();
	a.resize (n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		a[x - 1].pb (y - 1);
		a[y - 1].pb (x - 1);
	}
	dfs (0);
	for (auto i : m) {
		if (i.S > k)
			continue;
		cout << i.F << " ";
		F = 1;
	}
	cout << (F ? "YES" : "NO");
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
