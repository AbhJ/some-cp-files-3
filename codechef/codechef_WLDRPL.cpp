
/**
 * @author      : abhj
 * @created     : Wednesday Nov 17, 2021 23:49:14 IST
 * @filename    : a.cpp
 */

#include "bits/stdc++.h"
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

string s;
int l[N], r[N], m, n, dp[N][2], j;

int f (int i, int ty) {
	int &ans = dp[i][ty] = 0LL;
	for (j = i + 1; j <= n; j++) {
		if (s[j] == '(') {
			if (s[j - 1] == '-')
				ans -= f (j, 1LL ^ ty);
			else
				ans += f (j, ty);
			continue;
		}
		if (s[j] == ')')
			break;
		if (s[j] == '?') {
			if (s[j - 1] == '-')
				ans -= 1LL ^ ty;
			else
				ans += ty;
			continue;
		}
		assert (s[j] == '+' or s[j] == '-');
	}
	return ans;
}

void solve() {
	cin >> s >> m;
	n = s.length();
	s = "#" + s;
	f (1, 0);
	f (1, 1);
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		cout << (l[i] == r[i] ? 1LL : dp[l[i]][1]) << " ";
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

