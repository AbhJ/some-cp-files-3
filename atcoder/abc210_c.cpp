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
int n, k, c[N], cnt;
map<int, int>m;
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		m[c[i]]++;
		if (i <= k) {
		}
		else {
			m[c[i - k]]--;
			if (m[c[i - k]] == 0)
				m.erase(c[i - k]);
		}
		cnt = max(cnt, (int)m.size());
	}
	cout << cnt;
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}