
/**
 * @author      : abhj
 * @created     : Friday Nov 19, 2021 11:18:04 IST
 * @filename    : a.cpp
 */

#include "bits/stdc++.h"
#include "atcoder/all"
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
using namespace atcoder;
using mint = modint998244353;
const int inf  =     1e18 + 10;
const int N    =     2e5 + 1;

mint dp[N], pr[N];
int in1, in2, a[N], n;

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) {
			dp[i] = pr[i] = 1;
			continue;
		}
		dp[i] = dp[i - 1];
		if (a[i] == a[i - 2] and a[i - 1] != a[i])
			dp[i] = dp[i - 2] + dp[i - 1];
		if (a[i] != a[i - 2])
			in2 = i - 2;
		if (a[i] == a[i - 1])
			in1 = i - 1;
		if (in2 > in1)
			dp[i] = dp[i] + pr[in2] - pr[in1];
		pr[i] = pr[i - 1] + dp[i];
	}
	cout << dp[n].val();
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
