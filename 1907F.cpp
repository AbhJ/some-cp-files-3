#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
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

pii count_and_last_position (bool increasing) {
	int cnt = 0, posi = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (increasing and a[i] < a[i + 1]) {
			cnt++;
			posi = i;
		}
		if (!increasing and a[i] > a[i + 1]) {
			cnt++;
			posi = i;
		}
	}
	return mp (cnt, posi);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	auto [cntInc, posiInc] = count_and_last_position (true);
	auto [cntDec, posiDec] = count_and_last_position (false);
	if (cntDec == 0) {
		// completely increasing array
		cout << 0;
		return;
	}
	if (cntInc == 0) {
		// completely decreasing array
		cout << 1;
		return;
	}
	int ans = inf;
	if (cntInc == 1 and a[1] <= a[n]) {
		// decreasing decreasing array
		int x = posiInc, y = n - posiInc;
		ans = min ({ans, 1 + x, 1 + y});
		// one extra reversal because we end at reversed sorted array
	}
	if (cntDec == 1 and a[1] >= a[n]) {
		// increasing increasing array
		int x = posiDec, y = n - posiDec;
		ans = min ({ans, 2 + x, y});
		// two swaps may be needed to reverse and unreverse the array
	}
	if (ans == inf)
		cout << - 1;
	else
		cout << ans;
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