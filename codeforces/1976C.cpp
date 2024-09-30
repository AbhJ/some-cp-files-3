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
int n, m, a[N], b[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n + m + 1; i++)
		cin >> a[i];
	for (int i = 1; i <= n + m + 1; i++)
		cin >> b[i];
	vi p, t;
	vi isP (n + m + 2), isT (n + m + 2);
	for (int i = 1; i <= n + m + 1; i++) {
		if (p.size() == n + 1)
			t.pb (i);
		else if (t.size() == m + 1)
			p.pb (i);
		else if (a[i] >= b[i])
			p.pb (i);
		else
			t.pb (i);
	}
	int ans = 0;
	for (auto i : p) {
		ans += a[i];
		isP[i]++;
	}
	for (auto i : t) {
		ans += b[i];
		isT[i]++;
	}
	for (int i = 1; i <= n + m + 1; i++) {
		if (p.size() == n + 1) {
			// programmers can skip testers need to be replaced by programmers
			if (isP[i])
				cout << ans - a[i];
			else {
				cout << ans - b[i] + b[*p.rbegin()] - a[*p.rbegin()];
			}
		}
		if (t.size() == m + 1) {
			// testers can skip programmers need to be replaced by testers
			if (isT[i])
				cout << ans - b[i];
			else {
				cout << ans - a[i] + a[*t.rbegin()] - b[*t.rbegin()];
			}
		}
		cout << " ";
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