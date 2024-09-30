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
int n, a[N], lc, ans, cnt;
set<int> isInA;
vi fac;

vi fact (int n) {
	vi v;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			v.pb (i);
			if (i * i != n)
				v.pb (n / i);
		}
	}
	return v;
}

void solve() {
	cin >> n;
	lc = 1;
	ans = 0;
	isInA.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		lc = lcm (a[i], lc);
		if (a[i] > 1e9 or lc > 1e9)
			ans = n;
		isInA.emplace (a[i]);
	}
	sort (a + 1, a + 1 + n);
	reverse (a + 1, a + 1 + n);
	if (lc > a[1] or ans == n) {
		cout << n;
		return;
	}
	fac = fact (a[1]);
	for (auto targetLCM : fac) if (!isInA.count (targetLCM)) {
			lc = 1;
			cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (targetLCM % a[i] == 0) {
					cnt++;
					lc = lcm (a[i], lc);
				}
			}
			if (lc == targetLCM and cnt)
				// target LCM should not be in the array
				ans = max (cnt, ans);
		}
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