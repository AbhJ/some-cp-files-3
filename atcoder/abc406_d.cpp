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
int n, m, q, x, y;
set<int> r[N], c[N];

void solve() {
	cin >> n >> m >> q;
	while (q--) {
		cin >> x >> y;
		r[x].emplace (y);
		c[y].emplace (x);
	}
	cin >> q;
	while (q--) {
		cin >> x >> y;
		if (x == 1) {
			// y is row
			cout << r[y].size();
			for (auto z : r[y])
				c[z].erase (y);
			r[y].clear();
		}
		else {
			// y is col
			cout << c[y].size();
			for (auto z : c[y])
				r[z].erase (y);
			c[y].clear();
		}
		cout << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}