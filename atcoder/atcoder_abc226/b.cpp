
/**
 * @author      : abhj
 * @created     : Sunday Nov 07, 2021 19:29:18 IST
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

int n;
set<vi>s;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		vi a (l);
		for (auto &I : a)
			cin >> I;
		s.emplace (a);
	}
	cout << (int)s.size();
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
