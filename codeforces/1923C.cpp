#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
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
int n, q, cnt[N], a[N], cnt1[N];
void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[i] = cnt[i - 1] + a[i];
		cnt1[i] = cnt1[i - 1] + (a[i] == 1);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == r) {
			cout << "NO\n";
			continue;
		}
		if (cnt[r] - cnt[l - 1] < cnt1[r] - cnt1[l - 1] + r - l + 1)
			cout << "NO\n";
		else cout << "YES\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
