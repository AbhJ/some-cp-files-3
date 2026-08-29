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

int n, q, t[4 * N], lazy[4 * N], a[N];
string s;

void f (int v, int tl, int tr) {
	t[v] += lazy[v];
	if (tl != tr) {
		lazy[v * 2] += lazy[v];
		lazy[v * 2 + 1] += lazy[v];
	}
	lazy[v] = 0;
}

void build (int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = a[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build (v * 2, tl, tm);
		build (v * 2 + 1, tm + 1, tr);
		t[v] = min (t[v * 2], t[v * 2 + 1]);
	}
}

int query (int l, int r, int v = 1, int tl = 1, int tr = n) {
	f (v, tl, tr);
	if (l > tr or r < tl)
		return inf;
	if (l <= tl and r >= tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return min (query (l, r, v * 2, tl, tm), query (l, r, v * 2 + 1, tm + 1, tr));
}

void update (int l, int r, int new_val, int v = 1, int tl = 1, int tr = n) {
	f (v, tl, tr);
	if (l > tr or r < tl) return;
	if (l <= tl and r >= tr) {
		lazy[v] += new_val;
		f (v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	update (l, r, new_val, v * 2, tl, tm);
	update (l, r, new_val, v * 2 + 1, tm + 1, tr);
	t[v] = min (t[v * 2], t[v * 2 + 1]);
}

void solve() {
	cin >> n >> s >> q;
	for (int i = 1; i <= n; i++)
		a[i] = a[i - 1] + (s[i - 1] == 'A' ? 1 : -1);
	build (1, 1, n);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i;
			char c;
			cin >> i >> c;
			if (s[i - 1] == c)
				continue;
			int diff = (c == 'A' ? 2 : -2);
			s[i - 1] = c;
			update (i, n, diff, 1, 1, n);
		}
		if (type == 2) {
			int l, r;
			cin >> l >> r;
			int prev_p = (l == 1 ? 0 : query (l - 1, l - 1, 1, 1, n));
			if (query (l, r, 1, 1, n) >= prev_p)
				cout << "Yes";
			else
				cout << "No";
			cout << "\n";
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}