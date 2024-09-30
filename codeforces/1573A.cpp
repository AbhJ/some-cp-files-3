

/**
 * @author      : abhj
 * @created     : Saturday Sep 18, 2021 20:07:13 IST
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

int n, taka;
string s;

void solve() {
	cin >> n >> s;
	for (int i = n - 2; i > - 1; i--) {
		taka += s[i] - '0';
		taka += !! (s[i] - '0');
	}
	cout << taka + s[n - 1] - '0';
	taka = 0;
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
