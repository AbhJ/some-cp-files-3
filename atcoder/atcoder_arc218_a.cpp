
/**
 * @author      : abhj
 * @created     : Friday Nov 19, 2021 13:42:37 IST
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

int n, a[N], ty, b[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1])
			b[i] ^= 1, b[i - 1] ^= 1;
	}
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
