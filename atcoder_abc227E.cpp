
/**
 * @author      : abhj
 * @created     : Monday Nov 15, 2021 20:14:37 IST
 * @filename    : e.cpp
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
int k;
map<pair<string, int>, int> m;

void solve() {
	cin >> s >> k;
	function <int (string, int)> dfs = [&] (string s, int k) -> int {
		int n = s.length();
		if (k < 0)
			return 0;
		if (n <= 1)
			return 1;
		if (m.count (mp (s, k)))
			return m[mp (s, k)];
		for (char c : "KEY") {
			for (int i = 0; i < n; i++)
				if (c == s[i]) {
					m[mp (s, k)] += dfs (s.substr (0, i) + s.substr (i + 1), k - i);
					/*
					 * IF THE STRING IS POSSIBLE IN LOWER NUMBER OF SWAPS, NO NEED FOR
					 * CONSIDER THE POSSIBILITIES OF HIGHER NUMBER OF SWAPS LATER.
					 */
					break;
				}
		}
		return m[mp (s, k)];
	};
	cout << dfs (s, k);
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
