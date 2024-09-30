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
int s[N], t[N], p[N], n;
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> i[t];
		i[p - 1] = i[t];
	}
	for (int i = 0; i < 2 * n; i++) {
		p[(i + 1) % n] = min(p[i % n] + s[(i % n) + 1], p[(i + 1) % n]);
	}
	for (int i = 0; i < n; i++) {
		cout << p[i] << "\n";
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}