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
	vpii posi (n);
	int posiMax = - 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == n)
			posiMax = i;
		posi[i - 1] = mp (a[i], i);
	}
	sort (posi.begin(), posi.end());
	int nn = n;
	for (auto [val, pos] : posi) if ((pos & 1) == (posiMax & 1)) {
			b[pos] = n--;
		}
	for (auto [val, pos] : posi) if ((pos & 1) != (posiMax & 1)) {
			b[pos] = n--;
		}
	for (int i = 1; i <= nn; i++) {
		cout << b[i] << " ";
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