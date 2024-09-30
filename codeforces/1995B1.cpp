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
int n, k, a[N], pre[N], l, r, m, ans;

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	ans = 0;
	for (int i = 1; i <= n; i++) if (a[i] <= k) {
			int l = i, r = n, m;
			while (l < r) {
				bool flag = true;
				m = (l + r + 1) / 2;
				if (a[m] - a[i] > 1)
					flag = false;
				if (pre[m] - pre[i - 1] > k)
					flag = false;
				if (flag)
					l = m;
				else
					r = m - 1;
			}
			int cnt = 0, posi = l;
			if (upper_bound (a + i, a + posi, a[i]) == a + i) {
				// all are of same cost easy
				ans = max (ans, (posi - i + 1) * a[i]);
				continue;
			}
			int posiNew = upper_bound (a + i, a + posi, a[i]) - a;
			ans = max (ans, (posi - posiNew + 1) * a[posi] + (posiNew - 1 - i + 1) * a[i]);
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