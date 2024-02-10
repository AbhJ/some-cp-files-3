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
int n, a[N], b[N], t[4 * N];
// building the tree
void build (int a[], int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = a[tl];
	}
	else {
		int tm = (tl + tr) / 2;
		build (a, v * 2, tl, tm);
		build (a, v * 2 + 1, tm + 1, tr);
		t[v] = max (t[v * 2], t[v * 2 + 1]);
	}
}
// queries
int ma (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r)
		return - inf;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return max (ma (l, min (r, tm), v * 2, tl, tm), ma (max (l, tm + 1), r,
	            v * 2 + 1, tm + 1, tr));
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	build (a);
	// a[k] <= b[i] for all k in [i, j]
	// b[k] >= b[i] for all k in [i, j]
	// where i is the element being considered and
	// a[j] == b[i] is the closest possible j to i
	int j = 1;
	for (int i = 1; i <= n; i++) {
		while (j != n + 1 and ma (min (i, j), max (i, j)) != b[i])
			j++;
	}
	cout << (j != n + 1 ? "YES" : "NO");
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