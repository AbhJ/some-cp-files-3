
/**
 * @author      : abhj
 * @created     : Monday Feb 21, 2022 10:31:03 IST
 * @filename    : d.cpp
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

int n, a[N], cnt, ans, val;
stack<pair<int, int>>s;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (s.empty() == 0 and s.top().S == a[i]) {
			cnt = s.top().F, val = s.top().S;
			s.pop();
			ans -= cnt;
			if (cnt + 1 != val) {
				s.emplace (cnt + 1, val);
				ans += cnt + 1;
			}
		}
		else if (s.empty() == 0 and s.top().S != a[i]) {
			s.emplace (1, a[i]);
			ans++;
		}
		else if (s.empty() == 1) {
			s.emplace (1, a[i]);
			ans++;
		}
		else
			assert (0);
		cout << ans << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
