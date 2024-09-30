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

int a[3][3];

bool f (vvi &col, bool cur = false) {
	bool isComp = true;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (!col[i][j])
				isComp = false;
	if (isComp) {
		// game is won by cur
		set<int> r[3], c[3], d[2];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				r[i].emplace (col[i][j]);
				c[j].emplace (col[i][j]);
				if (i == j)
					d[0].emplace (col[i][j]);
				if (i + j == 2)
					d[1].emplace (col[i][j]);
			}
		for (int i = 0; i < 3; i++)
			if (r[i].size() == 1 or c[i].size() == 1 or (i != 2 and d[i].size() == 1))
				return !cur;
		// game is drawn
		vi sco (2);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				sco[col[i][j] - 1] += a[i][j];
		if (sco[0] >= sco[1])
			return false;
		return true;
	}
	// not all colored but game over
	// game is won by cur
	set<int> r[3], c[3], d[2];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			r[i].emplace (col[i][j]);
			c[j].emplace (col[i][j]);
			if (i == j)
				d[0].emplace (col[i][j]);
			if (i + j == 2)
				d[1].emplace (col[i][j]);
			if (col[i][j] == 0) {
				r[i].emplace (- 1);
				r[i].emplace (- 2);
				c[j].emplace (- 1);
				c[j].emplace (- 2);
				if (i == j) {
					d[0].emplace (- 1);
					d[0].emplace (- 2);
				}
				if (i + j == 2) {
					d[1].emplace (- 1);
					d[1].emplace (- 2);
				}
			}
		}
	for (int i = 0; i < 3; i++)
		if (r[i].size() == 1 or c[i].size() == 1 or (i != 2 and d[i].size() == 1))
			return !cur;
	// game is still going on
	bool canWin = false;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (!col[i][j]) {
				// 1 is for tak and 2 is for aok
				col[i][j] = 1 + (int) cur;
				canWin |= cur == f (col, !cur);
				col[i][j] = 0;
			}
	if (canWin)
		return cur;
	return !cur;
}

void solve() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	vvi col (3, vi (3, 0));
	cout << (!f (col) ? "Takahashi" : "Aoki");
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}