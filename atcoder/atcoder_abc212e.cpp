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
int q, p[N], x[N], delta;
multiset<pii> X;
void solve() {
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> p[i]; x[i] = - 1;
		if (p[i] != 3)
			cin >> x[i];
		if (p[i] == 1) {
			X.emplace(x[i] - delta, x[i] - delta);
		}
		if (p[i] == 2) {
			delta += x[i];
		}
		if (p[i] == 3) {
			auto [val, del] = *X.begin();
			// val + delta - del
			// val - del
			cout << del + delta << "\n";
			X.erase(X.begin());
		}
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}