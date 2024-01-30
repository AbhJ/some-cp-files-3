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
int n, k, m;
string s, ans;

void solve() {
	ans.clear();
	cin >> n >> k >> m >> s;
	set<char> vis;
	for (int i = 0; i < m; i ++) {
		vis.emplace (s[i]);
		if (vis.size() == k) {
			vis.clear();
			ans += s[i];
		}
	}
	if (ans.size() >= n) {
		cout << "YES";
		return;
	}
	cout << "NO\n";
	for (char i = 'a'; i < 'a' + k; i++) {
		if (vis.count (i) == 0) {
			ans += string (n - ans.size(), i);
			cout << ans;
			return;
		}
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