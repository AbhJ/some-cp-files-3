
/**
 * @author      : abhj
 * @created     : Thursday Nov 11, 2021 17:47:04 IST
 * @filename    : e.cpp
 */

#include "bits/stdc++.h"
#include "atcoder/all"
// #define int          long long int
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
using namespace atcoder;
using mint = modint998244353;
// const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;

int n, m, u, v, deg[N], E, vis[N];
vi a[N];

void solve() {
	cin >> n >> m;
	dsu d (n);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		d.merge (u - 1, v - 1);
		deg[u - 1]++;
		deg[v - 1]++;
		a[u - 1].pb (v - 1);
		a[v - 1].pb (u - 1);
	}
	vvi g = d.groups();
	function < void (int, int)> dfs = [&] (int u, int p) -> void {
		vis[u] = 1;
		for (auto i : a[u]) {
			E++;
			if (vis[i] == 0)
				dfs (i, u);
		}
	};
	for (auto& v : g) {
		if (v.size() == 1) {
			cout << 0;
			return;
		}
		E = 0;
		dfs (v[0], - 1);
		if ((E >> 1LL) != (int)v.size()) {
			cout << 0;
			return;
		}
	}
	cout << (((mint) 2).pow (g.size()).val());
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
