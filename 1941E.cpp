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
#define mp           make_pair
#define pb           emplace_back
#define F            first
#define S            second
#define int          long long int
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     1e2 + 10;
const int M    =     2e5 + 10;
int n, m, k, d, pre[N];

void solve() {
	cin >> n >> m >> k >> d;
	d++;
	vvi a (n, vi (m + 1));
	vvi dp (n, vi (m + 1));
	vi cost (n + 1, inf);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	for (int i = 0; i < n; i++) {
		multiset<int> s;
		s.emplace (1);
		dp[i][0] = 1;
		for (int j = 1; j < m; j++) {
			dp[i][j] = *s.begin() + 1 + a[i][j];
			if (j >= d)
				s.erase (s.find (dp[i][j - d]));
			if (j + d >= m - 1) {
				cost[i] = min (cost[i], (j != m - 1 ? 1 : 0) + dp[i][j]);
			}
			s.emplace (dp[i][j]);
		}
	}
	int ans = - 1;
	for (int i = 0; i < n; i++) {
		if (i == 0)
			pre[i] = cost[i];
		else
			pre[i] = pre[i - 1] + cost[i];
		if (i >= k - 1) {
			if (ans == - 1)
				ans = pre[i] - (i - k == - 1 ? 0 : pre[i - k]);
			else
				ans = min (ans, pre[i] - (i - k == - 1 ? 0 : pre[i - k]));
		}
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
