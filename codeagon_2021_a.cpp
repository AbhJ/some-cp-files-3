
/**
 * @author      : abhj
 * @created     : Sunday Oct 03, 2021 19:04:08 IST
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

int n, ans;
string s;

void solve() {
	cin >> s;
	n = s.length();
	for (int i = 2; i < n; i++) {
		string t = s.substr (i - 2, 3);
		sort (t.begin(), t.end());
		if (t[0] == t[1] and t[0] != t[2]) {
			cout << 1;
			return;
		}
		reverse (t.begin(), t.end());
		if (t[0] == t[1] and t[0] != t[2]) {
			cout << 1;
			return;
		}
	}
	cout << 0;
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
