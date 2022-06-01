
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Tuesday May 31, 2022 20:35:41 IST
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

int n, k;
string s;

void last (set<int> &ones) {
	if (ones.empty() or * ones.rbegin() == n - 1)
		return;
	int cost = n - 1 - *ones.rbegin();
	if (cost <= k) {
		k -= cost;
		swap (s[n - 1], s[*ones.rbegin()]);
		ones.erase (prev (ones.end()));
		ones.emplace (n - 1);
	}
}
void first (set<int> &ones) {
	if (ones.empty() or * ones.begin() == 0)
		return;
	if (ones.size() == 1 and * ones.begin() == n - 1)
		return;
	int cost = *ones.begin();
	if (cost <= k) {
		k -= cost;
		swap (s[0], s[*ones.begin()]);
		ones.erase (ones.begin());
		ones.emplace (0);
	}
}

void solve() {
	cin >> n >> k >> s;
	set<int>ones;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			ones.emplace (i);
	}
	last (ones);
	first (ones);
	int cnt = 0;
	for (int i = 1; i < n; i++)
		cnt += 10 * (s[i - 1] - '0') + (s[i] - '0');
	cout << cnt;
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

