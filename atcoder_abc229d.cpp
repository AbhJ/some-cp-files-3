
/**
 * @author      : abhj
 * @created     : Monday Nov 29, 2021 20:40:41 IST
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

string s;
int n, cnt, ans, tmp, j;

void solve() {
	cin >> s >> n;
	cnt = s[0] == '.';
	for (int i = 0; i < s.length(); i++) {
		while (j < s.length() - 1 and cnt + (s[j + 1] == '.') <= n)
			j++, cnt += s[j] == '.';
		if (cnt <= n)
			ans = max (j - i + 1, ans);
		cnt -= s[i] == '.';
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
