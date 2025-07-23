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
const int N    =     2e2 + 10;
// vis[i] <= 2, cntVisits <= 200
int n, m, c[N], vis[N], ans = inf, x, k;
// vis is animal visit count
// cntVisits is total zoo visit count
vi a[N];
void f (int curZoo, int cntSameZooVisits, int cntVisits, int cost) {
	if (cntVisits > 200 or cost >= ans)
		return;
	if (curZoo == n + 1) {
		for (int i = 1; i <= m; i++)
			if (vis[i] < 2)
				return;
		ans = min (cost, ans);
		return;
	}
	// vis curZoo
	for (auto i : a[curZoo]) {
		vis[i]++;
	}
	if (cntSameZooVisits < 2)
		f (curZoo, cntSameZooVisits + 1, cntVisits + 1, cost + c[curZoo]);
	for (auto i : a[curZoo])
		vis[i]--;
	// don't visit curZoo
	f (curZoo + 1, 0, cntVisits, cost);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= m; i++) {
		cin >> k;
		while (k--) {
			cin >> x;
			a[x].pb (i);
		}
	}
	f (1, 0, 0, 0);
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}