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
int n, m, k, x, cnt;
set <int> forb[N], dishesHavingIng[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> x;
			forb[i].emplace (x);
			dishesHavingIng[x].emplace (i);
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> x;
		for (int j : dishesHavingIng[x]) {
			if (forb[j].size() == 1)
				cnt++;
			forb[j].erase (x);
		}
		cout << cnt << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}