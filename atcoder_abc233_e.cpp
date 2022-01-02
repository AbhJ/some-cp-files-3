
/**
 * @author      : abhj
 * @created     : Thursday Dec 30, 2021 11:43:43 IST
 * @filename    : e.cpp
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

string s;
int n, sum[N], carry;
vi dig;

void solve() {
	cin >> s;
	n = s.length();
	sum[0] = s[0] - '0';
	for (int i = 1; i < n; i++)
		sum[i] = s[i] + sum[i - 1] - '0';
	for (int i = n - 1; ~i; i--) {
		dig.pb ((sum[i] + carry) % 10);
		carry = (sum[i] + carry) / 10;
	}
	while (carry != 0) {
		dig.pb (carry % 10);
		carry /= 10;
	}
	reverse (dig.begin(), dig.end());
	for (auto i : dig)
		cout << i;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
