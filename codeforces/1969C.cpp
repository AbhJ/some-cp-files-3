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
int n, k, a[N];
vvi dp;

int f() {
	// may not always work
	while (k--) {
		vvi v;
		for (int i = 0; i < n; i++) {
			if (i != 0 and a[i - 1] < a[i])
				v.pb (vi {a[i] - a[i - 1], i, - 1});
			if (i != n - 1 and a[i + 1] < a[i])
				v.pb (vi {a[i] - a[i + 1], i, + 1});
		}
		sort (v.begin(), v.end());
		if (!v.empty()) {
			a[v.back()[1]] = a[v.back()[1] + v.back()[2]];
		}
	}
	return accumulate (a, a + n, 0LL);
}

int g (int pos = 0, int K = k) {
	int mi = inf, ans = inf, su = 0;
	if (K < 0)
		return inf;
	if (pos == n)
		return 0;
	if (~dp[pos][K])
		return dp[pos][K];
	for (int i = pos; i < n; i++) {
		mi = min (mi, a[i]);
		// either change all elements from pos to i or dont change any
		int chCount = (i - pos + 1) - 1;
		if (chCount > K)
			break;
		ans = min (ans, g (i + 1, K - chCount) + mi * (chCount + 1));
	}
	return dp[pos][K] = min (ans, g (pos + 1, K) + a[pos]);
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp = vvi (n + 1, vi (k + 1, - 1));
	cout << min(f(), g());
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