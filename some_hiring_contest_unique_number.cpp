
/**
 * @author      : abhj
 * @created     : Friday Nov 12, 2021 20:08:45 IST
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

void solve() {
	string s, t;
	cin >> s >> t;
	int cnt = 0;
	int n = s.length(), m = t.length();
	string S;
	for (int i = 0; i + m <= n; i++) {
		string tmp = s.substr (i, m);
		int ok = 1;
		for (int j = 0; j < m; j++) {
			if (tmp[j] != t[j] and t[j] != '#')
				ok = 0;
		}
		cnt += ok;
		if (ok)
			S += to_string (i + 1);
	}
	if(cnt)
		cout << S;
	else
		cout << "0";
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
