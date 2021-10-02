
/**
 * @author      : abhj
 * @created     : Saturday Oct 02, 2021 18:09:25 IST
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

int n, cnt;
vpii v;

void solve() {
	cin >> n;
	map<int, int>m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.pb (x, 0);
		v.pb (x + y, 1);
	}
	sort (v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (i != 0)
			m[cnt] += (v[i].F - v[i - 1].F);
		if (v[i].S == 0)
			cnt++;
		else
			cnt--;
	}
	for (int i = 1; i <= n; i++)
		cout << m[i] << " ";
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
