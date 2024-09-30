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
int n, k, a[N], x, ans = inf;
set<int> s;

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x] = i;
	}
	for (int i = 1; i <= n + 1; i++) {
		if (i != n + 1)
			s.emplace (a[i]);
		if (s.size() == k + 1) {
			s.erase (a[i - k]);
		}
		if (s.size() == k)
			ans = min (ans, *prev (s.end()) - *s.begin());
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}