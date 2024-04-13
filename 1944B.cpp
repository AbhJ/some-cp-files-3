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
int n, k, a[N];

bool is_same_side (int l, int r) {
	if (l < n and r >= n)
		return false;
	return true;
}

void solve() {
	cin >> n >> k;
	vvi pos (n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
		pos[a[i] - 1].pb (i);
	}
	vi l, r, d;
	for (int i = 0; i < n; i++) {
		if (is_same_side (pos[i][0], pos[i][1])) {
			if (pos[i][0] < n) {
				l.pb (pos[i][0]);
				l.pb (pos[i][1]);
			}
			else {
				r.pb (pos[i][0]);
				r.pb (pos[i][1]);
			}
		}
		else {
			d.pb (pos[i][0]);
			d.pb (pos[i][1]);
		}
	}
	for (int i = 0; i < (int)d.size(); i++) {
		l.pb (d[i]);
		r.pb (d[++i]);
	}
	for (int i = 0; i < k * 2; i++) {
		cout << a[l[i]] << " ";
	}
	cout << "\n";
	for (int i = 0; i < k * 2; i++) {
		cout << a[r[i]] << " ";
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