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
using vi       =     std::vector<bool>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;
int n, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
string s[2];

void solve() {
	cin >> n >> s[0] >> s[1];
	queue <pii> q;
	q.emplace (0, 0);
	vvi vis (2, vi (n, false));
	while (q.empty() == 0) {
		int x = q.front().F, y = q.front().S;
		q.pop();
		if (x == 1 and y == n - 1) {
			cout << "YES";
			return;
		}
		for (int k = 0; k < 4; k++) {
			int X = x + dx[k], Y = y + dy[k];
			if (X < 0 or X > 1 or Y < 0 or Y > n - 1)
				continue;
			if (X == 1 and Y == n - 1) {
				cout << "YES";
				return;
			}
			if (s[X][Y] == '<') {
				Y--;
			}
			else if (s[X][Y] == '>') {
				Y++;
			}
			if (vis[X][Y])
				continue;
			vis[X][Y] = true;
			q.emplace (X, Y);
		}
	}
	cout << "NO";
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