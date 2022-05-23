
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Monday May 23, 2022 12:57:55 IST
 * @filename    : c.cpp
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

int n, d[N], p[N], l;

void solve() {
	cin >> n >> l;
	vpii v (n);
	vpii out (n);
	map<int, int> ind;
	for (int i = 0; i < n; i++)
		cin >> p[i] >> d[i];
	for (int i = 0; i < n; i++) {
		if (d[i] == 0)
			out[i] = {p[i], p[i]};
		else
			out[i] = {l - p[i], p[i]};
		ind[p[i]] = i;
		v[i] = {p[i], i};
	}
	sort (out.begin(), out.end());
	sort (v.begin(), v.end());
	int I = 0, J = n - 1;
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j + 1 != n and out[j + 1].F == out[j].F)
			j++;
		vi fall;
		for (int pos = i; pos <= j; pos++) {
			if (d[ind[out[pos].S]] == 0)
				fall.pb (v[I++].S);
			else
				fall.pb (v[J--].S);
		}
		sort (fall.begin(), fall.end());
		for (auto val : fall)
			cout << ++val << " ";
		i = j;
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t, x = 0;
	cin >> t;
	while (t--) {
		cout << "Case #" << ++x << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
