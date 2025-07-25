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
int n, a[N], first, last;
int solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int s = a[0] * 2, g = a[n - 1];
	sort (a, a + n);
	int j = 2;
	for (int i = 1; i < n; j++) {
		if (s < a[i])
			return - 1;
		while (i < n and s >= a[i]) {
			i++;
			if (s >= g)
				return j;
		}
		s = a[i - 1] * 2;
	}
	return n;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		cout << solve();
		cout << "\n";
	}
	return 0;
}