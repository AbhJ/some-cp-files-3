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
int n, m, u, v, w;
vpii a[N];

int parent[N], ra[N];
//disjoint set union dsu
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
void make_set (int v) {
	parent[v] = v;
	ra[v] = 0;
}
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (ra[a] < ra[b])
			swap (a, b);
		parent[b] = a;
		if (ra[a] == ra[b])
			ra[a]++;
	}
}

bool dfs (int u, int fi, vi &path, int pa) {
	path.pb (u);
	if (u == fi)
		return true;
	for (auto [v, w] : a[u]) {
		if (pa != v and dfs (v, fi, path, u))
			return true;
	}
	path.pop_back();
	return false;
}

void solve() {
	cin >> n >> m;
	vector <tuple <int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edges.pb (w, u, v);
	}
	for (int i = 1; i <= n; i++) {
		make_set (i);
		a[i].clear();
	}
	sort (edges.rbegin(), edges.rend());
	auto best_edge = make_tuple (inf, - 1, - 1);
	for (auto [w, u, v] : edges) {
		if (find_set (u) == find_set (v)) {
			// this might be the smallest cycle edge
			best_edge = make_tuple (w, u, v);
		}
		else {
			// if they are getting connected now, they will be edges of the dfs tree
			union_sets (u, v);
			a[u].pb (v, w);
			a[v].pb (u, w);
		}
	}
	auto [W, U, V] = best_edge;
	vi path;
	dfs (U, V, path, 0);
	cout << W << " " << path.size() << "\n";
	for (auto i : path)
		cout << i << " ";
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