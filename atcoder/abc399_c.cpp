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
//disjoint set union dsu
int par[N], siz[N], n, u, v, ans, m;
int find_set (int v) {
	if (v == par[v])
		return v;
	return par[v] = find_set (par[v]);
}
void make_set (int v) {
	par[v] = v;
	siz[v] = 1;
}
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (siz[a] < siz[b])
			swap (a, b);
		par[b] = a;
		siz[a] += siz[b];
		siz[b] = 0;
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		make_set (i);
	while (m--) {
		cin >> u >> v;
		if (find_set (u) == find_set (v))
			ans++;
		else
			union_sets (u, v);
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}