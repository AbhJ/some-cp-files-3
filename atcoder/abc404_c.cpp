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
int n, m, u, v, vis[N], cnt;
vi a[N];

bool dfs (int cur, int par = - 1) {
	vis[cur] = 1;
	for (auto nex : a[cur]) if (nex != par and a[cur].size() == 2) {
			if (vis[nex] == 1)
				return true;
			if (dfs (nex, cur))
				return true;
		}
	return false;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		a[u].pb (v);
		a[v].pb (u);
	}
	if (m == n)
		for (int i = 1; i <= n; i++) if (vis[i] == 0) {
				if (dfs (i)) {
					cnt++;
				}
			}
	cout << (cnt == 1 ? "Yes" : "No");
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}