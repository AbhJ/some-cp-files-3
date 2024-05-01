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
int n, k, a[N], lef, ans;

bool f (int m, int k) {
	lef = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > m) {
			lef ++;
		}
		else if (m - a[i] > k)
			return false;
		else
			k -= m - a[i];
	}
	ans = max (ans, lef + k + 1 + (m - 1) * n);
	return true;
}

void solve() {
	cin >> n >> k;
	ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// here we are binary searching on the number of full
	// scale repitions {of the type 1,2,...,n}
	// per repition it gives at least 1 + (m - 1) * n
	// sequences of permutations
	int l = 0, r = inf, m;
	while (l < r) {
		m = (l + r + 1) >> 1;
		if (f (m, k))
			l = m;
		else
			r = m - 1;
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