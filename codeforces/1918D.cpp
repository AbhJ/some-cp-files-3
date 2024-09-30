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
int n, l, r, m, a[N], dp[N], pre[N];

// dp[i] = minimum sum of the selected elements such that all the range sums are <= m
// so we have to ensure that the range sums inside never cross m
// for that we use the deque to store only the elements in the last range [j + 1, i - 1]

bool f() {
	priority_queue <pair<int, int>> pq;
	pq.emplace (0, 0);
	for (int i = 1; i <= n + 1; i++) {
		// [pq.top().S, i - 1] should form a subsegment
		while (pq.empty() == 0 and pre[i - 1] - pre[pq.top().S] > m)
			pq.pop();
		dp[i] = -pq.top().F + a[i];
		pq.emplace (- dp[i], i);
	}
	return dp[n + 1] <= m;
}


void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	a[n + 1] = 0;
	l = 0, r = inf;
	while (l < r) {
		m = l + r >> 1;
		if (f())
			r = m;
		else
			l = m + 1;
	}
	cout << r;
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