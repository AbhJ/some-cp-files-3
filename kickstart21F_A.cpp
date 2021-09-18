

/**
 * @author      : abhj
 * @created     : Saturday Sep 18, 2021 22:34:42 IST
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

int n;
string s;
void solve() {
	cin >> n >> s;
	int cos = 0;
	vi l (n), r (n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			l[i] = i;
		else
			l[i] = (i == 0 ? - inf : l[i - 1]);
	}
	for (int i = n - 1; i > - 1; i--) {
		if (s[i] == '1')
			r[i] = i;
		else
			r[i] = (i == n - 1 ? inf : r[i + 1]);
	}
	for (int i = 0; i < n; i++)
		cos += min (i - l[i], r[i] - i);
	cout << cos;
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	int t, x = 0;
	cin >> t;
	while (t--) {
		cout << "Case #" << ++x << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
