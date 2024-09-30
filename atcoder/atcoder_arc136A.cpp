
/**
 * @author      : abhj
 * @created     : Saturday Mar 05, 2022 12:03:33 IST
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

int n, ans, tmp;
string s, t;

void solve() {
	// BA -> AB
	// BB -> A
	cin >> n >> s;
	t += s[0];
	for (int i = 1; i < n; i++) {
		if (t.back() == 'B' and s[i] == 'B') {
			t.pop_back();
			t += 'A';
		}
		else if (t.back() == 'B' and s[i] == 'A') {
			t.pop_back();
			t += "AB";
		}
		else
			t += s[i];
	}
	cout << t;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
