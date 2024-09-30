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
int n, ans;
string s, t;
map <string, bool> dp;

bool isDone (string& s) {
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i])
			return false;
	}
	return true;
}

void solve() {
	cin >> n >> s >> t;
	n += 2;
	s += "..";
	t += "..";
	queue <pair <string, int>> q;
	q.emplace (s, n - 2);
	bool fl = false;
	string sx = s, tx = t;
	sort (sx.begin(), sx.end());
	sort (tx.begin(), tx.end());
	if (sx != tx) {
		cout << - 1;
		return;
	}
	while (q.empty() == 0) {
		int z = q.size();
		while (z--) {
			auto [s, emp] = q.front();
			q.pop();
			if (emp == n - 2 and isDone (s)) {
				fl = true;
				break;
			}
			if (dp.count (s))
				continue;
			dp[s] = true;
			for (int i = 0; i < n - 1; i++) {
				if (i == emp or i + 1 == emp or i == emp + 1)
					continue;
				swap (s[i], s[emp]);
				swap (s[i + 1], s[emp + 1]);
				q.emplace (s, i);
				swap (s[i], s[emp]);
				swap (s[i + 1], s[emp + 1]);
			}
		}
		if (fl)
			break;
		ans++;
	}
	if (fl == false)
		cout << - 1;
	else
		cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}