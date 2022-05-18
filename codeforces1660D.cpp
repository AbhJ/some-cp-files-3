
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Wednesday May 18, 2022 23:14:46 IST
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

int n, a[N], L, R;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	function <void ()> small_cases = [&]() {
		int maxi = 1, mini = 1, ans = 0;
		map<int, int>m;
		for (int i = 0; i < n; i++) {
			int mi = min ({a[i], a[i] * mini, a[i] * maxi});
			int ma = max ({a[i], a[i] * mini, a[i] * maxi});
			swap (mi, mini);
			swap (ma, maxi);
			ans = max ({ans, maxi, mini});
			if (m.count (ans) == 0)
				m[ans] = i;
		}
		if (ans == 0) {
			cout << 0 << " " << n;
			return;
		}
		int l = 0, prod = 1;
		for (int j = m[ans]; j > - 1; j--) {
			prod *= a[j];
			l = j;
			if (prod == ans)
				break;
		}
		cout << l << " " << n - 1 - m[ans];
	};
	int ans = 0;
	function <void (int, int, vi &, vi &)> f = [&] (int l, int r, vi & pref_sign, vi & pref_cnt) {
		if ((pref_sign[r] - (l == 0 ? 0 : pref_sign[l - 1])) & 1)
			return;
		if ((pref_cnt[r] - (l == 0 ? 0 : pref_cnt[l - 1])) > ans) {
			ans = pref_cnt[r] - (l == 0 ? 0 : pref_cnt[l - 1]);
			L = l, R = r;
		}
	};
	function <void ()> large_cases = [&]() {
		vi zeros;
		zeros.pb (- 1);
		vi pref_sign (n), pref_cnt (n);
		for (int i = 0; i < n; i++) {
			if (a[i] == 0)
				zeros.pb (i);
			pref_sign[i] = ((i == 0 ? 0 : pref_sign[i - 1]) + (a[i] < 0));
			pref_cnt[i] = ((i == 0 ? 0 : pref_cnt[i - 1]) + (a[i] == 2 or a[i] == - 2));
		}
		zeros.pb (n);
		L = 0;
		R = -1;
		for (int i = 0; i < zeros.size() - 1; i++) {
			int l = zeros[i], r = zeros[i + 1];
			for (int j = l + 1; j < r; j++) {
				f (l + 1, j, pref_sign, pref_cnt);
				f (j, r - 1, pref_sign, pref_cnt);
			}
		}
		cout << " " << L << " " << n - 1 - R;
	};
	if (n < 65) {
		small_cases();
		return;
	}
	large_cases();
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
