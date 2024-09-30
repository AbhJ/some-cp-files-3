
/**
 * @author      : abhj
 * @created     : Sunday Sep 19, 2021 18:02:44 IST
 * @filename    : a.cpp
 */

#include "bits/stdc++.h"
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

int n, k[N];
vvi a;

void solve() {
	cin >> n;
	a.clear();
	a.resize (n);
	queue<int>q;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			int tmp;
			cin >> tmp;
			a[tmp - 1].pb (i);
		}
		if (k[i] == 0)
			q.emplace (i);
	}
	vi vis (n), d (n);
	while (q.empty() == 0) {
		int i = q.front();
		q.pop();
		vis[i] = 1;
		for (auto j : a[i]) {
			k[j]--;
			if (k[j] == 0)
				q.emplace (j);
			if (j > i)
				d[j] = max (d[j], d[i]);
			else
				d[j] = max (d[j], d[i] + 1);
		}
	}
	if (count (vis.begin(), vis.end(), 0) != 0) {
		cout << - 1;
		return;
	}
	cout << 1 + *max_element (d.begin(), d.end());
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
