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

string s;
int n;

char fl (char x) {
	return 'U' + 'D' - x;
}

map <string, int> dp;

bool f (string s, bool cur = true) {
	vi pos;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'U')
			pos.pb (i);
	}
	if (s.length() == 1) {
		if (pos.empty())
			return !cur;
		return cur;
	}
	if (dp.count (s))
		return (dp[s] ? cur : !cur);
	bool ans = false;
	for (auto i : pos) {
		string nex;
		if (i == 0) {
			nex = s.substr (1);
			nex[0] = fl (nex[0]);
			nex[nex.length() - 1] = fl (nex[nex.length() - 1]);
		}
		else if (i == s.length() - 1) {
			nex = s.substr (0, s.length() - 1);
			nex[0] = fl (nex[0]);
			nex[nex.length() - 1] = fl (nex[nex.length() - 1]);
		}
		else {
			nex = s;
			nex[i - 1] = fl (nex[i - 1]);
			nex[i + 1] = fl (nex[i + 1]);
			nex.erase (nex.begin() + i);
		}
		ans |= cur == f (nex, !cur);
	}
	dp[s] = ans;
	return ans ? cur : !cur;
}

void solve() {
	cin >> n >> s;
	if (n < 10) {
		cout << (f (s) ? "YES" : "NO");
	}
	else {
		vi pos;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'U')
				pos.pb (i);
		}
		cout << (pos.size() & 1 ? "YES" : "NO");
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