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

int n, x, a[N], pre[N], dp [N];

void solve() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pre[i + 1] = pre[i] + a[i];
	}
	int ans = 0;
	for (int i = n - 1; ~i; i--) {
		if (lower_bound (pre, pre + 1 + n, pre[i] + x) == pre + 1 + n) {
			dp[i] = n - i;
			continue;
		}
		int posi = lower_bound (pre, pre + 1 + n, pre[i] + x) - pre;
		if (x != pre[posi] - pre[i])
			dp[i] = dp[posi] - 1;
		else
			dp[i] = dp[posi + 1];
		dp[i] += posi - i;
	}
	for (int i = 0; i < 2 * n; i++) {
		ans += dp[i];
		dp[i] = 0;
		pre[i] = 0;
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