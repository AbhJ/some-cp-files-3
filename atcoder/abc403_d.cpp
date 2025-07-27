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
int n, d, a[N], ans;
map<int, int> v[N];
map <int, int> dp[2];
int f (int pre, map <int, int> &m, bool lasChosen = 0) {
	if (m.upper_bound (pre) == m.end())
		return 0;
	int cur = m.upper_bound (pre) -> F;
	if (dp[lasChosen].count (cur))
		return dp[lasChosen][cur];
	if (lasChosen == 1 or pre == - 1)
		return dp[lasChosen][cur] = min (m[cur] + f (cur, m, 1), f (cur, m, 0));
	else if (cur - pre == d)
		return dp[lasChosen][cur] = m[cur] + f (cur, m, 1);
	else
		return dp[lasChosen][cur] = min (m[cur] + f (cur, m, 1), f (cur, m, 0));
}

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (d != 0)
			v[a[i] % d][a[i]]++;
		else v[0][a[i]]++;
	}
	if (d == 0) {
		for (auto i : v[0])
			ans += max (0LL, i.S - 1);
	}
	else
		for (int i = 0; i < d; i++) if (v[i].empty() == 0) {
				ans += f (- 1, v[i]);
			}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}