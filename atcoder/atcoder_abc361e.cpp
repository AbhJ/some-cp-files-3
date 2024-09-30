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
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;

vvpii edges;
int n, u, v, e, far, ans;
vi dis;
void dfs (int cur, int par = - 1, int d = 0) {
	if (dis[cur] == - 1)
		dis[cur] = d;
	else
		return;
	if (dis[cur] > dis[far])
		far = cur;
	for (auto [tar, edg] : edges[cur]) if (tar != par) {
			dfs (tar, cur, d + edg);
		}
}

void solve() {
	cin >> n;
	edges.resize (n);
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> e;
		edges[u - 1]. pb (v - 1, e);
		edges[v - 1].pb (u - 1, e);
		ans += (e << 1LL);
	}
	dis = vi (n, - 1);
	far = 0;
	dfs (0);
	dis = vi (n, - 1);
	dfs (far);
	cout << ans - dis[far];
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}