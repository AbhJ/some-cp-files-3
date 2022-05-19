
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Thursday May 19, 2022 13:09:01 IST
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

int n, a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[n - 1 - i];
	int cnt = 0;
	for (int i = 1; i < n;) {
		if (a[i] == a[0])
			i++;
		else {
			i <<= 1;
			cnt++;
		}
	}
	cout << cnt;
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
