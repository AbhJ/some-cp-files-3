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
int n, q, a[N], del;
void solve() {
	cin >> n >> q;
	iota (a, a + n, 1);
	while (q--) {
		int ty, x, y;
		cin >> ty >> x;
		if (ty == 2) {
			x--;
			// precompute
			cout << a[ (x + del) % n] << "\n";
		}
		if (ty == 1) {
			x--;
			cin >> y;
			a[ (x + del) % n] = y;
		}
		if (ty == 3) {
			del = (del + x) % n;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}