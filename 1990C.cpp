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
int n, a[N], b[N];

void solve() {
	cin >> n;
	map<int, int> ma;
	int la = 0, ans = 0;
	set<int>s;
	vi v;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ma[a[i]]++;
		if (ma[a[i]] > 1) {
			s.emplace (a[i]);
		}
		if (s.empty())
			b[i] = 0;
		else b[i] = *s.rbegin();
		ans += a[i] + b[i];
	}
	ma.clear();
	s.clear();
	// after the second operation the pattern is guaranteed
	for (int i = 1; i <= n; i++) {
		ma[b[i]]++;
		if (ma[b[i]] > 1) {
			s.emplace (b[i]);
		}
		if (s.empty())
			a[i] = 0;
		else a[i] = *s.rbegin();
		ans += a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans += a[i] * (n - i);
	}
	cout << ans;
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