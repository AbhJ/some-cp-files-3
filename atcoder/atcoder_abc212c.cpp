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
int n, a[N], b[N], m;
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	sort(b + 1, b + 1 + m);
	vi v;
	for (int i = 1; i <= n; i++) {
		int bam = - inf, dan = inf;
		auto it = upper_bound(b + 1, b + 1 + m, a[i]);
		if (it < b + 1 + m and it > b)
			dan = *it;
		it = prev(it);
		if (it < b + 1 + m and it > b) {
			bam = *it;
		}
		v.pb(a[i] - bam);
		v.pb(dan - a[i]);
	}
	cout << *min_element(v.begin(), v.end());
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}