
/**
 * @author      : abhj
 * @created     : Saturday Sep 18, 2021 17:36:19 IST
 * @filename    : b.cpp
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

string s[N];

void solve() {
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	for (auto i : s[3]) {
		int cur = i - '1';
		cout << s[cur];
	}
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
