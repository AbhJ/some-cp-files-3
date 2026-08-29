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

int n, k, a[N], pre, ma;
map<int, int> dp;

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		pre = (pre + a[i]) % k;
		int cur = ma;
		if (dp.contains (pre))
			cur = max (1 + dp[pre], cur);
		dp[pre] = cur;
		ma = max (cur, ma);
	}
	cout << ma;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}