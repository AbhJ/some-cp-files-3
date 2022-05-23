
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Sunday May 22, 2022 16:34:43 IST
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

int n;
string s;

void solve() {
	cin >> n >> s;
	int upp = 0, low = 0, dig = 0, spe = 0;
	for (auto c : s) {
		if (c >= 'A' and c <= 'Z')
			upp++;
		else if (c >= 'a' and c <= 'z')
			low++;
		else if (c >= '0' and c <= '9')
			dig++;
		else
			spe++;
	}
	if (upp == 0)
		s += "A";
	if (low == 0)
		s += "a";
	if (dig == 0)
		s += "0";
	if (spe == 0)
		s += "#";
	while (s.length() < 7)
		s += "A";
	cout << s;
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
