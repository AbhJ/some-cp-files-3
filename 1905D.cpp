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
int n, a[N], b[N], mini[N], dp[N], zero;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
		if (a[i] == 0)
			zero = i;
	}
	for (int i = 0; i < n; i++) {
		b[i] = a[zero + i];
	}
	mini[n] = inf;
	for (int i = n - 1; ~i; i--) {
		mini[i] = min (b[i], mini[i + 1]);
	}
	// mex [0, i] is mini [i + 1, n]
	stack <int> s;
	for (int i = 0; i < n; i++) {
		while (s.empty() == 0 and b[s.top()] > b[i])
			s.pop();
		// if we wanted minimum mex this would make sense
		// if (s.empty() == 0 and b[i] == mini[i])
		if (s.empty() == 0)
			dp[i] = dp[s.top()] + b[i] * (i - s.top());
		s.push (i);
	}
	// if we wanted minimum mex this would make sense
	// cout << dp[n - 1] + n;
	cout << *max_element (dp, dp + n) + n;
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