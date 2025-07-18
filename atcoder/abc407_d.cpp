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
const int N    =     1e2 + 2;
int n, m, a[N][N], ans = - 1;
bool vis[N][N];
bool isVisPlacement (int i, int j, bool x) {
	if (x == 0)
		return vis[i][j + 1];
	return vis[i + 1][j];
}

// implement countAns
int countAns (pii curState) {
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (vis[i][j] == 0)
				ans ^= a[i][j];
	return ans;
}

void turnOn (pii curState, pii nexState) {
	vis[curState.F][curState.S] = true;
	vis[nexState.F][nexState.S] = true;
}

void turnOff (pii curState, pii nexState) {
	vis[curState.F][curState.S] = false;
	vis[nexState.F][nexState.S] = false;
}

// fix visited
void dfs (int i, int j) {
	pii curState = {i, j};
	if (vis[i][j]) {
		dfs (i, j + 1);
		return;
	}
	if (i >= n) {
		ans = max (ans, countAns (curState));
		return;
	}
	if (j > m - 1) {
		dfs (i + 1, 0);
		return;
	}
	if (j <= m - 2) {
		if (isVisPlacement (i, j, 0) == 0) {
			// horizontal placement
			pii nexState = {i, j + 1};
			turnOn (curState, nexState);
			dfs (i, j + 2);
			turnOff (curState, nexState);
		}
	}
	if (i <= n - 2) {
		if (isVisPlacement (i, j, 1) == 0) {
			// vertical placement
			pii nexState = {i + 1, j};
			turnOn (curState, nexState);
			dfs (i, j + 1);
			turnOff (curState, nexState);
		}
	}
	dfs (i, j + 1);
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	dfs (0, 0);
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}