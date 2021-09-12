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
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define all(x)       x.begin(), x.end()
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     1e5 + 10;
int n, m, x[N], y[N], c[N], d[N], vis[N]; vector<tuple<int, int, int>> a[N];
void dfs(int u, int p = - 1) {
	for (auto [X, C, D] : a[u])if (p != X) {
			if (vis[X] == - 1 or vis[X] > vis[u] + C + D / (vis[u] + 1)) {
				vis[X] = vis[u] + C + D / (vis[u] + 1);
				dfs(X, u);
			}
		}
}
int f(int st) {
	memset(vis, - 1, sizeof vis);
	vis[1] = st;
	dfs(1);
	return vis[n];
}
void solve() {
	cin >> n >> m;

	rep(i, 1, m) {
		cin >> x[i] >> y[i] >> c[i] >> d[i];
		a[x[i]].pb(y[i], c[i], d[i]);
		a[y[i]].pb(x[i], c[i], d[i]);
	}
	priority_queue<pii, vpii, greater<pii>>q;
	q.emplace(0, 1);
	fill(vis + 2, vis + N, inf);
	while (q.empty() == 0) {
		auto [dis, pos] = q.top();
		q.pop();
		if (dis > vis[pos])
			continue;
		for (auto [X, C, D] : a[pos]) {
			int tim = max(vis[pos], (int)ceil(sqrt(D)) - 1);
			if (vis[X] > tim + C + D / (tim + 1)) {
				vis[X] = tim + C + D / (tim + 1);
				q.emplace(vis[X], X);
			}
		}
	}
	cout << (vis[n] == inf ? - 1 : vis[n]);
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	int t; cin >> t;
	while (t--) {
		solve(); cout << "\n";
	}
	return 0;
}
