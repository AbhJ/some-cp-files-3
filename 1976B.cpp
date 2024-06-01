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
	int cos = 0, mi = inf;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n + 1; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++) {
		// between a and b
		if (a[i] <= b[n + 1] and b[i] >= b[n + 1])
			mi = min (mi, 1LL);
		else if (a[i] >= b[n + 1] and b[i] <= b[n + 1])
			mi = min (mi, 1LL);
		else mi = min (mi, 1LL + min (abs (a[i] - b[n + 1]), abs (b[i] - b[n + 1])));
		cos += abs (b[i] - a[i]);
	}
	cout << mi + cos;
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