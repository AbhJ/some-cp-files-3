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
int n, m, ans;
pii v[N];

void solve() {
	cin >> n >> m;
	ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].F;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].S;
	}
	sort (v, v + n);
	for (int i = 0; i < n; i++) if (v[i].F <= m) {
			int p1 = v[i].F, c1 = v[i].S;
			int p2 = p1 + 1, c2 = 0;
			if (i != n - 1 and v[i + 1].F == p2)
				c2 = v[i + 1].S;
			// tar1 is cnt of flower p1 target
			// tar2 is cnt of flower p2 target
			int tar1 = min (c1, m / p1);
			int tar2 = min (c2, (m - tar1 * p1) / p2);
			// now we convert some flower p1 to flower p2
			int conv_cos = min ({tar1, c2 - tar2, m - tar1 * p1 - tar2 * p2});
			ans = max (ans, tar1 * p1 + tar2 * p2 + conv_cos);
		}
	cout << ans;
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