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
const int N    =     1e3 + 10;
int n, m, ans = 1, cnt, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
string s[N];
vpii v;

void dfs (int x, int y) {
	cnt++;
	s[x][y] = '@';
	for (int k = 0; k < 4; k++) {
		int X = x + dx[k], Y = y + dy[k];
		if (X < 0 or X >= n or Y < 0 or Y >= m)
			continue;
		if (s[X][Y] == '#') {
			v.pb (x, y);
			return;
		}
	}
	for (int k = 0; k < 4; k++) {
		int X = x + dx[k], Y = y + dy[k];
		if (X < 0 or X >= n or Y < 0 or Y >= m or s[X][Y] != '.')
			continue;
		dfs (X, Y);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '.') {
				dfs (i, j);
				ans = max (ans, cnt);
				cnt = 0;
				for (auto [x, y] : v)
					s[x][y] = '.';
				v.clear();
			}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}