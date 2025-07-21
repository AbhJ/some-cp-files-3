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
int n, m;
string s[N];
// distance, x, y
priority_queue <tuple <int, int, int>> q;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char ch[4] = {'^', '<', 'v', '>'};

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = '#' + s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'E') {
				q.emplace (0, i, j);
			}
		}
	}
	while (q.empty() == 0) {
		auto [dist, x, y] = q.top();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int X = x + dx[k], Y = y + dy[k];
			if (X <= n and Y <= m and X >= 1 and Y >= 1 and s[X][Y] == '.') {
				s[X][Y] = ch[k];
				q.emplace (make_tuple (dist - 1, X, Y));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << s[i].substr (1) + '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}