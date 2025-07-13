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
using pii      =     std::pair<int, bool>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;
int n, m, l, r, cnt, ans = inf;
vector <pii> v;

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		v.pb (l, 1);
		v.pb (r + 1, 0);
	}
	sort (v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		//handle zeroes
		if (i != 0 and v[i].F == v[i - 1].F and v[i].S == 1 and v[i - 1].S == 0
		        and cnt == 0)
			ans = 0;
		//update answer when one node is completed
		if (i != 0 and v[i].F != v[i - 1].F)
			ans = min (ans, cnt);
		if (v[i].S == 0)
			cnt--;
		else
			cnt++;
	}
	if (v[0].F != 1 or v.back().F != n + 1)
		ans = 0;
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}