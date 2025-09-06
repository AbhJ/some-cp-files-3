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
int n, m, X, x, y;
vpii a[N];
priority_queue < tuple<int, int, int>>q;
bool vis[N][2];

void solve() {
	cin >> n >> m >> X;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x].pb (y, 0);
		a[y].pb (x, 1);
	}
	// cost, index, current state
	q.emplace (0, 1, 0);
	while (q.empty() == 0) {
		auto [cos, u, f] = q.top();
		q.pop();
		if (u == n) {
			cout << - cos;
			return;
		}
		if (vis[u][f])
			continue;
		vis[u][f] = true;
		for (auto [v, ty] : a[u]) {
			if (f == ty)
				q.emplace (cos - 1, v, f);
			else
				q.emplace (cos - X - 1, v, f ^ 1);
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}