
/**
 * @author      : abhj
 * @created     : Sunday Jan 30, 2022 13:08:15 IST
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

int n, ans, ll, &rr = n;
string s;

void solve() {
	cin >> n >> s;
	n--;
	for (char c = 'a'; c <= 'z'; c++) {
		int l = ll, r = rr;
		while (l < r) {
			while (l < r and s[r] >= c)
				r--;
			while (l < r and s[l] < c)
				l++;
			if (l != r)
				swap (s[l], s[r]);
			else
				break;
			ll = l + 1;
			rr = r - 1;
		}
	}
	cout << s;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
