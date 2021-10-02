
/**
 * @author      : abhj
 * @created     : Saturday Oct 02, 2021 17:44:45 IST
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

int n;
string s;

void solve() {
	cin >> s;
	n = s.length();
	int ans = 0;
	for (int i = 0; i < (1LL << n); i++) {
		string t1, t2;
		for (int I = 0; I < n; I++) {
			if ((i >> I) & 1LL)
				t1 += s[I];
			else
				t2 += s[I];
		}
		sort (t1.begin(), t1.end(), greater<char>());
		sort (t2.begin(), t2.end(), greater<char>());
		if (t1.empty() == 1 or t2.empty() == 1)
			continue;
		if (t1[0] == '0' or t2[0] == '0')
			continue;
		stringstream in1 (t1), in2 (t2);
		int inte1, inte2;
		in1 >> inte1, in2 >> inte2;
		ans = max (ans, inte1 * inte2);
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
