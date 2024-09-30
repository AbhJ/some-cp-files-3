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
// README the crux of the problem is either the x's don't intersect or the y's dont intersect (INCLUSIVE or)
pii by_x[N], by_y[N]; multiset<int> X, Y; int x[N], y[N], n;
static bool cmp(pii a, pii b) {
	return a.S < b.S;
}
void solve() {
	cin >> n;
	rep(i, 1, n) {
		cin >> x[i] >> y[i];
	}
	rep(i, 1, n) {
		X.emplace(x[i]);
		Y.emplace(y[i]);
		by_x[i] = by_y[i] = mp(x[i], y[i]);
	}
	sort(by_x + 1, by_x + 1 + n);
	sort(by_y + 1, by_y + 1 + n, cmp);
	int fir_x = by_x[1].F, fir_y = by_y[1].S, las_x = by_x[n].F, las_y = by_y[n].S;
	int ans = inf, mi_y = inf, mi_x = inf, ma_x = 0, ma_y = 0;
	rep(i, 1, n - 1) {
		Y.erase(Y.find(by_x[i].S));
		X.erase(X.find(by_y[i].F));
		ans = min({ans, (by_x[i].F - fir_x) * ((ma_y = max(ma_y, by_x[i].S)) - (mi_y = min(mi_y, by_x[i].S))) + (las_x - by_x[i + 1].F) * (*rbegin(Y) - *begin(Y)), (by_y[i].S - fir_y) * ((ma_x = max(ma_x, by_y[i].F)) - (mi_x = min(mi_x, by_y[i].F))) + (las_y - by_y[i + 1].S) * (*rbegin(X) - *begin(X))});
	}
	X.erase(X.begin());
	Y.erase(Y.begin());
	assert((int)X.size() + (int)Y.size() == 0);
	cout << (ans == inf ? 0 : ans);
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve(); cout << "\n";
	}
	return 0;
}