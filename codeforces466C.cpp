
/**
 * @author      : abhj
 * @created     : Friday May 06, 2022 14:45:01 IST
 * @filename    : c.cpp
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
vi a;

void solve() {
	cin >> n;
	a.resize (n);
	for (auto &i : a)
		cin >> i;
	int cnt = 0, sum = std::accumulate (a.begin(), a.end(), 0LL);
	if (sum % 3 == 0) {
		vector<int> pre (n);
		int pre_sum = 0;
		for (int i = 0; i < n - 1; i++) {
			pre_sum += a[i];
			if (pre_sum == sum / 3)
				pre[i] = 1 + (i == 0 ? 0 : pre[i - 1]);
			else
				pre[i] = (i == 0 ? 0 : pre[i - 1]);
			if (pre_sum == sum * 2 / 3)
				cnt += (i >= 1 ? pre[i - 1] : 0);
		}
	}
	cout << cnt;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
