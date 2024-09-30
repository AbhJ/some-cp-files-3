//Coded by Abhijay Mitra (AbJ)
#include "bits/stdc++.h"
#define double       long double
#define int          long long int
#define ibs          ios_base::sync_with_stdio(false)
#define cti          cin.tie(0)
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
const int N    =     2e6 + 10;
int n, m, a[N], b[N], c[N];
void solve() {
	cin >> n >> m;
	vi l, r;
	rep(i, 1, n) {
		cin >> a[i];
		if (a[i] == 1)
			r.pb(i);
		if (a[i] == 2)
			l.pb(i);
	}
	rep(i, 1, m) {
		cin >> b[i];
	}
	rep(i, 1, m) {
		c[i] = inf;
		if (b[i] == 1)
			c[i] = 0;
		if (lower_bound(all(l), b[i]) != l.end()) {
			c[i] = min(c[i], (*lower_bound(all(l), b[i])) - b[i]);
		}
		if (upper_bound(all(r), b[i]) != r.begin()) {
			c[i] = min(c[i], b[i] - (*prev(upper_bound(all(r), b[i]))));
		}
		cout << (c[i] == inf ? - 1 : c[i]) << " ";
	}
}
int32_t main() {
	ibs; cti;
	// solve(); return 0;
	int t; cin >> t;
	while (t--) {
		solve(); cout << "\n";
	}
	return 0;
}