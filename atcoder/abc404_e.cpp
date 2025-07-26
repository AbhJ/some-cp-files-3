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
int n, a[N], c[N], las, ans, dp[N];
int f (int cur) {
	if (cur == las)
		return 0;
	if (cur < las)
		return inf;
	int cnt = inf;
	if (~dp[cur])
		return dp[cur];
	for (int i = cur - 1; i >= max (cur - c[cur], las); i--) {
		cnt = min (1 + f (i), cnt);
	}
	return dp[cur] = cnt;
}
void solve() {
	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> c[i];
	for (int i = 1; i < n; i++)
		cin >> a[i];
	fill (dp, dp + n, - 1);
	// las is the previous bowl that had a bean
	// technically the last bowl we HAD to touch
	for (int i = 1; i < n; i++) {
		if (a[i]) {
			ans += f (i);
			las = i;
		}
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}