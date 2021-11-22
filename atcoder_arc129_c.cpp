
/**
 * @author      : abhj
 * @created     : Monday Nov 22, 2021 16:08:45 IST
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

int n, tmp = 1;

void solve() {
	cin >> n;
	function <string (int)> f = [&] (int n) -> string {
		if (n == 0)
			return "";
		int m = ceil (sqrt (n << 1LL));
		while ((m * (m + 1)) > 2 * n)
			m--;
		for (int i = 0; i < m; i++)
			tmp *= 10, tmp %= 7;
		string r (m, '7');
		r += '0' + tmp;
		return r + f (n - (m * (m + 1) / 2));
	};
	string S = f (n);
	if (S.empty() == 0)
		S.pop_back();
	cout << S;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
