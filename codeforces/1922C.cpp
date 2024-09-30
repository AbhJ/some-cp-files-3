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

int n, m;

vi calc (vi a) {
	vi dp (n);
	dp [0] = 0, dp[1] = 1;
	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1] + abs (a[i] - a[i - 1]);
		if (abs (a[i] - a[i - 1]) < abs (a[i - 1] - a[i - 2]))
			dp[i] = min (dp[i], dp[i - 1] + 1);
	}
	return dp;
}

void solve() {
	cin >> n;
	vi a (n), b (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[n - i - 1] = a[i];
	}
	vi dp1 = calc (a), dp2 = calc (b);
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (x < y)
			cout << dp1[y] - dp1[x];
		else
			cout << dp2[n - y - 1] - dp2[n - x - 1];
		cout << "\n";
	}
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