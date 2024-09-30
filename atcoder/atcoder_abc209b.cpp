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
int n, x, a[N];
void solve() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= (i & 1 ^ 1);
	}
	cout << (accumulate(a + 1, a + 1 + n, 0LL) <= x ? "Yes" : "No");
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}
