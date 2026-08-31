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
int n, m, a[N], b[N], x, y, f[N];
void solve() {
	cin >> n >> m >> x >> y;
	fill (f, f + 1 + n + m, 0);
	for (int i = 0; i < x; i++) {
		cin >> a[i];
		f[a[i]] |= 1;
	}
	for (int i = 0; i < y; i++) {
		cin >> b[i];
		f[b[i]] |= 2;
	}
	int lx = 0, ly = 0, to = 0, lim = n + m - 1, ans = 0;
	for (int i = n + m; i; i--) {
		if (f[i] == 0 or to == lim)
			continue;
		if (f[i] == 1 and lx == n)
			continue;
		if (f[i] == 2 and ly == m)
			continue;
		ans += i;
		to++;
		if (f[i] == 1)
			lx++;
		if (f[i] == 2)
			ly++;
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