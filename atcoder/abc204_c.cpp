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
const int N    =     2e3 + 10;
int n, a[N], m, x[N], y[N], vis[N]; vi A[N];
int cnt = 0;
void dfs(int u, int p = - 1) {
    cnt++;
    vis[u] = 1;
    for (auto &i : A[u])if (p != i and vis[i] == 0) {
            vis[i] = 1;
            dfs(i, u);
        }
}
void solve() {
    cin >> n >> m;
    rep(i, 1, m) {
        cin >> x[i] >> y[i];
        A[x[i]].pb(y[i]);
    }
    rep(i, 1, n) {
        memset(vis, 0, sizeof vis);
        dfs(i);
    }
    cout << cnt;
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