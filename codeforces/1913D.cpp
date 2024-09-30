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
const int M    =     998244353;

int a[N], n, ans, t[4 * N];

int add (int a, int b) {
	a += b;
	return (a >= M ? a - M : a);
}

int mul (int a, int b) {
	return (a * b) % M;
}

int sub (int a, int b) {
	return (a - b + M) % M;
}

int powM (int b, int p) {
	int r = 1;
	for (; p; b = mul (b, b), p >>= 1)
		if (p & 1)
			r = mul (r, b);
	return r;
}

int invM (int x) {
	return powM (x, M - 2);
}

// building the tree
void build (int a[], int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = tl;
	}
	else {
		int tm = (tl + tr) / 2;
		build (a, v * 2, tl, tm);
		build (a, v * 2 + 1, tm + 1, tr);
		int lef = t[v * 2], rig = t[v * 2 + 1];
		if (a[lef] <= a[rig])
			t[v] = lef;
		else
			t[v] = rig;
	}
}
// queries
int mi (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	int lef = mi (l, min (r, tm), v * 2, tl, tm), rig = mi (max (l, tm + 1), r, v * 2 + 1, tm + 1, tr);
	if (a[lef] <= a[rig])
		return lef;
	return rig;
}

int f (int l, int r, int type) {
	if (l > r)
		return 1;
	int tmp = 0, m = mi (l, r);
	int lef = f (l, m - 1, type | 1), rig = f (m + 1, r, type | 2);
	tmp = add (tmp, mul (lef, rig));
	if (type & 1)
		tmp = add (tmp, lef);
	if (type & 2)
		tmp = add (tmp, rig);
	if (type == 3)
		tmp = sub (tmp, 1);
	return tmp;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build (a);
	cout << f (1LL, n, 0LL);
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	a[0] = inf;
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
