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
int n, m, c[N], a, ans, p[N];
void solve() {
	cin >> n >> m;
	fill (c, c + 1 + 2 * m, 0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		c[a]++;
	}
	fill (p, p + 1 + 2 * m, 0);
	for (int i = m; i; i--) {
		p[i] = p[i + 1] + c[i];
		ans = max (c[2 * i] + p[i], ans);
	}
	cout << ans;
	ans = 0;
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