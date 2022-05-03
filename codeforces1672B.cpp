
/**
 * @author      : abhj
 * @created     : Tuesday May 03, 2022 15:26:13 IST
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

string s;

void solve() {
	cin >> s;
	function <void (string)> f = [&] (string s) -> void {
		int su = 0;
		for (char &c : s) {
			su += c == 'A';
			su -= c == 'B';
			if (su < 0) {
				cout << "NO";
				return;
			}
		}
		cout << (s.back() == 'B' ? "YES" : "NO");
	};
	f (s);
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
