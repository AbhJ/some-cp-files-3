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
const int N    =     1e3 + 10;
int n, m, c, a[N][N], ans = inf, lef[N][N], rig[N][N];
void solve() {
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			lef[i][j] = rig[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			lef[i][j] = min({lef[i][j - 1], lef[i - 1][j], a[i][j] - c * i - c * j});
			// this guy has the lower j
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			rig[i][j] = min({rig[i][j + 1], rig[i - 1][j], a[i][j] - c * i + c * j});
			// this guy has the higher j
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = min({ans, a[i][j] + c * i + c * j + lef[i][j - 1], a[i][j] + c * i - c * j + rig[i][j + 1], a[i][j] + c * i - c * j + rig[i - 1][j], a[i][j] + c * i + c * j + lef[i - 1][j]});
		}
	}
	cout << ans;
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve();
	return 0;
}