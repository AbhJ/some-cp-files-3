
/**
 * @author      : abhj
 * @created     : Monday Sep 20, 2021 20:10:57 IST
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
map<int, vector<string>>dp;

vector<string> f (int n_tmp) {
	assert (n_tmp & 1 ^ 1);
	if (n_tmp == 0)
		return vector<string> {""};
	if (dp.count (n_tmp))
		return dp[n_tmp];
	vector<string> v = f (n_tmp - 2), cur;
	for (auto i : v) {
		cur.pb ("(" + i + ")");
		cur.pb ("()" + i);
		cur.pb (i + "()");
		if (cur.size() == n_tmp)
			break;
	}
	return dp[n_tmp] = cur;
}

void solve() {
	cin >> n;
	// auto v = f (n << 1);
	// while (n--)
	// cout << v[n] << "\n";
	char cur = ')';
	for (int i = 0; i < n; i++) {
		int r = n - (i + 1);
		string s;
		cur = ')';
		for (int j = 0; j < 2 * (i + 1); j++) {
			if (j % (i + 1) == 0) {
				if (cur == '(')
					cur = ')';
				else
					cur = '(';
			}
			s += cur;
		}
		for (int j = 0; j < 2 * r; j++)
			if (j & 1)
				s += ")";
			else
				s += "(";
		cout << s + "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
