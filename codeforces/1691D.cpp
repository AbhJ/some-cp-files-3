
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Wednesday Jun 01, 2022 15:43:01 IST
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

int n, a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], b[n + 1 - i] = a[i];
	function <bool (int [])> f = [&] (int a[]) -> bool {
		vector<int> pref (n + 1);
		for (int i = 1; i <= n; i++)
			pref[i] = a[i] + pref[i - 1];
		stack<int> s;
		for (int i = 1; i <= n; i++) {
			while (s.empty() == 0 and a[i] >= a[s.top()]) {
				if (pref[i - 1] - pref[s.top() - 1] > 0)
					return false;
				s.pop();
			}
			s.emplace (i);
		}
		return true;
	};
	cout << (f (a) and f (b) ? "YES" : "NO");
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
