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
int n, m, k, c, u, v, co;

vector<int> pa, ra;

void make_set (int v) {
	pa[v] = v;
	ra[v] = 0;
}

int find_set (int v) {
	if (v == pa[v])
		return v;
	return pa[v] = find_set (pa[v]);
}

void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (ra[a] < ra[b])
			swap (a, b);
		pa[b] = a;
		if (ra[a] == ra[b])
			ra[a]++;
	}
}

void solve() {
	cin >> n >> m;
	vector<tuple<int, int, int>> edges;
	pa.resize (n);
	ra.resize (n);
	for (int i = 0; i < n; i++)
		make_set (i);
	while (m--) {
		cin >> k >> c >> u;
		while (--k) {
			cin >> v;
			edges.pb (c, u - 1, v - 1);
		}
	}
	sort (edges.begin(), edges.end());
	for (auto [c, u, v] : edges) {
		if (find_set (u) != find_set (v)) {
			co += c;
			union_sets (u, v);
		}
	}
	for (int i = 1; i < n; i++) {
		if (find_set (i) != find_set (0)) {
			cout << - 1;
			return;
		}
	}
	cout << co;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}