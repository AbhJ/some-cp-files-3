
/**
 * @author      : abhj
 * @created     : Saturday Apr 23, 2022 13:18:17 IST
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
int n;

void solve() {
	cin >> s;
	vector<int>v{0};
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i - 1])
			v.pb (i);
	}
	v.pb (s.length());
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - v[i - 1] == 1) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
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
