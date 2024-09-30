
/**
 * @author      : abhj
 * @created     : Tuesday Apr 12, 2022 14:28:27 IST
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

int q, x, c, ty;
queue<pii> qu;

void solve() {
	cin >> q;
	while (q--) {
		cin >> ty;
		if (ty == 1) {
			cin >> x >> c;
			qu.emplace (x, c);
		}
		else {
			cin >> c;
			int su = 0;
			if (qu.empty()) {
				cout << "0\n";
				continue;
			}
			while (qu.empty() == 0 and c != 0) {
				auto p = qu.front();
				su += p.F * min (c, p.S);
				int cnt = min (c, p.S);
				c -= cnt;
				p.S -= cnt;
				qu.pop();
				if (p.S != 0)
					qu.emplace (p);
			}
			cout << su << "\n";
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
