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
const int N    =     2e3 + 10;
int n, m, x, y, w;
vector <pii> a[N];
bool isReachable[N][N];
void dfs (int u, int cu, int p = - 1) {
	isReachable [u][cu] = true;
	for (auto [v, we] : a[u])
		if (v != p)
			if (isReachable[v][we ^ cu] == false) {
				dfs (v, we ^ cu);
			}
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		a[x - 1].pb (y - 1, w);
	}
	dfs (0, 0);
	for (int i = 0; i < N; i++) {
		if (isReachable[n - 1][i]) {
			cout << i;
			return;
		}
	}
	cout << - 1;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}