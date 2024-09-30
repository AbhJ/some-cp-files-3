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
const int N    =     1e2 + 10;
int n, a[N], ti, ti_l, dp[N][(int)1e5 + 1];
int f(int ind, int dif, int l_su, int d_su) {
	if (ind == n + 1)
		return max(l_su, d_su);
	if (~dp[ind][l_su])return dp[ind][l_su];
	int &ans = dp[ind][l_su];
	ans = min(f(ind + 1, dif + a[ind], l_su + a[ind], d_su), f(ind + 1, dif - a[ind], l_su, d_su + a[ind]));
	return ans;
}
void solve() {
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a  + 1 + n);
	memset(dp, - 1, sizeof dp);
	cout << f(0, 0, 0, 0);
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