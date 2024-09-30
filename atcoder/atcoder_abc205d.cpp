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
int n, a[N], k[N], q, tmp, ans, cn[N];
void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cn[i] = a[i] - a[i - 1] + cn[i - 1] - 1;
	}
	for (int i = 1; i <= q; i++) {
		cin >> k[i];
	}
	for (int i = 1; i <= q; i++) {
		int cnt = lower_bound(cn + 1, cn + 1 + n, k[i]) - cn;
		if (cnt == n + 1) {
			cout << n + k[i] << "\n";
		}
		else
			// README
			// cn[cnt] is number of people  not seen till cnt
			// k[i] - a[cnt] - 1 is number of people not seen after cnt
			cout << a[cnt] - cn[cnt] + k[i] - 1 << "\n";
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}