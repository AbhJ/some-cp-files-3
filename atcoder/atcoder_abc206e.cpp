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
set<int>s; int l, r, cnt, dp[N];
vi fact(int n) {
	vi v;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			v.pb(i);
			if (i * i != n) {
				v.pb(n / i);
			}
		}
	}
	return v;
}
void solve() {
	cin >> l >> r;
	// for (int i = l; i <= r; i++) {
	// 	vi v = fact(i);
	// 	for (auto j : v) if (j >= l) {
	// 			s.insert(j);
	// 		}
	// }
	// we can do faster
	// for (auto i : s) {
	// 	cnt += (r / i) - ((l - 1) / i);
	// 	// cout << i << " ";
	// }
	for (int i = r; i >= 1; i--) {
		int &ekhon = dp[i] = (r / i) - ((l - 1) / i);
		ekhon *= ekhon;
		// consider all pairs and then remove the ones having gcd 1
		for (int j = (i << 1LL); j <= r; j += i) {
			// we should not count its multiples again
			ekhon -= dp[j];
		}
		if (i != 1)
			cnt += ekhon - (i >= max(2LL, l) ? r / i * 2 - 1 : 0);
	}
	cout << cnt;
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}