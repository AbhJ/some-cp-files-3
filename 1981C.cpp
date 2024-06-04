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
#include <random>
#include <time.h>
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

mt19937 rng (time (NULL));

int n, a[N], ans[N];

bool f (bool x) {
	bool isPatternConfirmed = false;
	if (x)
		for (int i = 1; i <= n / 2; i++) {
			swap (a[n + 1 - i], a[i]);
		}
	ans[0] = ans[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		ans[i] = 0;
		if (~a[i]) {
			ans[i] = a[i];
			isPatternConfirmed = true;
		}
		else {
			ans[i] = ans[i - 1] / 2;
			if (ans[i] == 0 and isPatternConfirmed == false) {
				ans[i] = - 1;
				continue;
			}
			if (ans[i] == 0)
				ans[i] = 2;
		}
	}
	for (int i = n; i >= 1; i--) if (!~a[i]) {
			ans[i] = max (ans[i], ans[i + 1] / 2);
			if (ans[i] == 0)
				ans[i] = 2;
		}
	for (int i = 1; i <= n - 1; i++) {
		if (ans[i] != ans[i + 1] / 2 and ans[i] / 2 != ans[i + 1]) {
			cout << - 1;
			return false;
		}
	}
	if (x)
		for (int i = 1; i <= n / 2; i++) {
			swap (ans[n + 1 - i], ans[i]);
		}
	return true;
}

void solve() {
	cin >> n;
	set<pii>s;
	// pattern of 1 2 1 2 or 2 1 2 1 can only be confirmed when we have a non - 1
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (f (uniform_int_distribution<int> (0, 1) (rng))) for (int i = 1; i <= n;
		        i++) {
			cout << ans[i] << " ";
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