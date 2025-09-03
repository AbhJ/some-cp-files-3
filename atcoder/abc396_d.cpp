#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
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
const int inf  =     8e18 + 10;
const int N    =     2e6 + 10;
int n, m, w, x, y, ans = inf;
vpii a[N];
vi vis;
void dfs (int u, int cur = 0) {
	for (auto [v, we] : a[u]) if (vis[v] == 0) {
			vis[v] = 1;
			dfs (v, cur ^ we);
			vis [v] = 0;
		}
	if (u == n)
		ans = min (ans, cur);
}
void solve() {
	cin >> n >> m;
	while (m--) {
		cin >> x >> y >> w;
		a[x].pb (y, w);
		a[y].pb (x, w);
	}
	vis = vi (n + 1);
	vis[1] = 1;
	dfs (1);
	cout << ans;
}
int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}