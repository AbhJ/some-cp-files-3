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
int n;
char s[2][N];
int dx[2] = {1, 0}, dy[2] = {0, 1};

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[0][i];
	for (int i = 0; i < n; i++)
		cin >> s[1][i];
	vvi dp (3, vi (n + 1));
	set<pii> q;
	int cnt = 0;
	string optimal;
	optimal += s[0][0];
	q.emplace (0, 0);
	while (!q.empty()) {
		char newc = '9';
		set <pii> newq;
		auto [x, y] = *q.begin();
		q.erase (q.begin());
		for (int k = 0; k < 2; k++) {
			int X = x + dx[k], Y = y + dy[k];
			if (X < 2 and Y < n) {
				if (s[X][Y] == newc) {
					newq.emplace (X, Y);
				}
				if (newc == '9' or s[X][Y] < newc) {
					newc = s[X][Y];
					newq = set <pii> ();
					newq.emplace (X, Y);
				}
			}
		}
		q = newq;
		if (newc != '9')
			optimal += string (1, newc);
	}
	for (int y = n - 1; y >= 0; y--) {
		for (int x = 1; x >= 0; x--) {
			if (x == 1 and y == n - 1) {
				dp[x][y] = 1;
				continue;
			}
			char cn = optimal[x + y];
			if (s[x][y] == cn)
				dp[x][y] = dp [x + 1][y] + dp [x][y + 1];
		}
	}
	cout << optimal << "\n";
	cout << dp[0][0];
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