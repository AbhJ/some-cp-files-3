#include "bits/stdc++.h"
#include "atcoder/dsu"
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
using namespace atcoder;
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;
int n, x, y, z, ind[N]; tuple <int, int, int> a[N];

static bool cmp(int x, int y) {
	return get<2>(a[x]) < get<2>(a[y]);
}

void solve() {
	cin >> n;
	int ans = 0;
	dsu dsu(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x >> y >> z;
		a[i] = make_tuple(x, y, z);
	}
	// each edge is responsible for the
	// product of cc size of nodes in the pair
	iota(ind + 1, ind + 1 + n, 1LL);
	sort(ind + 1, ind + 1 + n, cmp);
	for (int pos = 1; pos <= n; pos++) {
		int i = ind[pos];
		if (dsu.same(get<0>(a[i]), get<1>(a[i])) == 0)
			ans += (int)dsu.size(get<0>(a[i])) * (int)dsu.size(get<1>(a[i])) * get<2>(a[i]);
		dsu.merge(get<0>(a[i]), get<1>(a[i]));
	}
	cout << ans;
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}