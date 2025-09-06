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
int n, m, X[N], Y[N], Z[N], A[N];
bool imp;
vpii a[N];
vi v;

void dfs (int u) {
	v.pb (u);
	for (auto [v, w] : a[u]) {
		if (~A[v]) {
			if ((A[v] ^ A[u]) == w)
				continue;
			imp = true;
			return;
		}
		A[v] = A[u] ^ w;
		dfs (v);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> X[i] >> Y[i] >> Z[i];
		a[X[i]].pb (Y[i], Z[i]);
		a[Y[i]].pb (X[i], Z[i]);
	}
	fill (A + 1, A + 1 + n, - 1);
	for (int i = 1; i <= n; i++) if (A[i] == - 1) {
			A[i] = 0;
			v.clear();
			dfs (i);
			// now per bit check whether this is the optimal bit
			// if more numbers have jth bit set in this component
			// it should be unset in the minimal solution
			for (int j = 0; j < 60; j++) {
				int c0 = 0, c1 = 0;
				for (auto pos : v) {
					if ((1LL << j) & A[pos])
						c1++;
					else
						c0++;
				}
				if (c1 > c0)
					for (auto pos : v)
						A[pos] ^= (1LL << j);
			}
		}
	if (imp)
		cout << - 1;
	else
		for (int i = 1; i <= n; i++)
			cout << A[i] << " ";
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}