

/**
 * @author      : abhj
 * @created     : Saturday Oct 02, 2021 17:33:20 IST
 * @filename    : b.cpp
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

string a, b;

void solve() {
	cin >> a >> b;
	int cnt = 0;
	for (int i = 0; i < a.length() - 1; i++) {
		if (a[i] == b[i])
			continue;
		if (a[i] == b[i + 1] and b[i] == a[i + 1])
			cnt++, i++;
		else {
			cout << "No";
			return;
		}
	}
	if (cnt <= 1)
		cout << "Yes";
	else
		cout << "No";
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
