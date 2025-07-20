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
const int N    =     3e6 + 10;
int t[4 * N], n, q, u[N], v[N], ty, delW, totW, x, ind, l[N], r[N], w[N];
// building the tree
void build (int a[], int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = 1;
	}
	else {
		int tm = (tl + tr) / 2;
		build (a, v * 2, tl, tm);
		build (a, v * 2 + 1, tm + 1, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}
// queries
int sum (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (l, min (r, tm), v * 2, tl, tm)
	       + sum (max (l, tm + 1), r, v * 2 + 1, tm + 1, tr);
}
// update
void update (int pos, int new_val, int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] += new_val;
	}
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (pos, new_val, v * 2, tl, tm);
		else
			update (pos, new_val, v * 2 + 1, tm + 1, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

vi a[N];
// l[i] will be the assigned node value of subtree root i
// r[i] will be the max assigned node value among all nodes in subtree rooted at i

void dfs (int u, int p = 0) {
	l[u] = ++ind;
	for (int v : a[u]) if (v != p) {
			dfs (v, u);
		}
	r[u] = ind;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		cin >> u[i] >> v[i];
		a[u[i]].emplace_back (v[i]);
		a[v[i]].emplace_back (u[i]);
	}
	build (w);
	dfs (1);
	cin >> q;
	totW = n;
	while (q--) {
		cin >> ty;
		if (ty == 1) {
			cin >> x >> delW;
			update (l[x], delW);
		}
		else {
			cin >> x;
			// find parent among them
			// and then calculate subtree sum
			// ans will be total - 2 * subtree sum absolute
			int node1 = l[u[x]], node2 = l[v[x]], node = u[x];
			if (node1 < node2) {
				swap (node1, node2);
				node = v[x];
			}
			int total = sum (1, n);
			// node1 demarcates the subtree considered
			cout << abs (total - 2 * sum (l[node], r[node])) << "\n";
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}