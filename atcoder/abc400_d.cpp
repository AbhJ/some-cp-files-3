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
int n, m, a, b, c, d, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, dp[N][N];
string s[N];
priority_queue <tuple<int, int, int>> q;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = "#" + s[i];
		for (int j = 1; j <= m; j++)
			dp[i][j] = inf;
	}
	cin >> a >> b >> c >> d;
	q.emplace (0, a, b);
	while (q.empty() == 0) {
		auto [kick, x, y] = q.top();
		q.pop();
		if (x == c and y == d) {
			cout << - kick;
			return;
		}
		if (x < 1 or x > n or y < 1 or y > m or dp[x][y] != inf)
			continue;
		for (int k = 0; k < 4; k++) {
			int xx = dx[k] + x, yy = dy[k] + y;
			int X = dx[k] + xx, Y = dy[k] + yy;
			if (xx < 1 or xx > n or yy < 1 or yy > m or dp[xx][yy] != inf);
			else
				q.emplace (kick - (s[xx][yy] == '#'), xx, yy);
			if (X < 1 or X > n or Y < 1 or Y > m or dp[X][Y] != inf or s[X][Y] != '#');
			else
				q.emplace (kick - 1, X, Y);
		}
		dp[x][y] = kick;
	}
	cout << "ABJ";
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}