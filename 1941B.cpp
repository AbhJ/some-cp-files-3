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
int n, a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n - 1; i++) {
		if (a[i] == 0) {
			i++;
			continue;
		}
		if (a[i] >= 2 and i - 1 >= 0 and a[i - 1] >= 1 and i + 1 <= n - 1
		        and a[i + 1] >= 1) {
			int cnt = min ({a[i] / 2, a[i - 1], a[i + 1]});
			a[i - 1] -= cnt;
			a[i] -= 2 * cnt;
			a[i + 1] -= cnt;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
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