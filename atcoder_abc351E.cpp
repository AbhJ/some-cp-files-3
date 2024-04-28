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
int n, x, y, ans, X, Y;

vi xx[2], yy[2];

void f() {
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		X = x + y;
		Y = x - y;
		// now we know X and Y have same parity
		xx[X & 1].pb (X);
		yy[Y & 1].pb (Y);
	}
	// after rotation distances are half of manhattan distances
	// manhattan distances can be found out by sum of (i - (tot - i - 1)) x
	// ith element [0 indexed] beats i elements and is beaten by tot - i - 1
	for (int i = 0; i < 2; i++) {
		sort (xx[i].begin(), xx[i].end());
		sort (yy[i].begin(), yy[i].end());
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < 2; j++) if (i < xx[j].size()) {
				ans += i * xx[j][i] - (xx[j].size() - i - 1) * xx[j][i];
				ans += i * yy[j][i] - (yy[j].size() - i - 1) * yy[j][i];
			}
	cout << (ans >> 1);
}

vpii v[2][2];

int dis (pii a, pii b) {
	int lef = a.F - b.F;
	int rig = a.S - b.S;
	return max ({lef, - lef, rig, - rig});
}

void solveSelf (vpii v) {
	for (int i = 0; i < v.size(); i++)
		for (int j = i + 1; j < v.size(); j++) {
			ans += dis (v[i], v[j]);
		}
}

void solveDiff (vpii v, vpii z) {
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < z.size(); j++) {
			ans += dis (v[i], z[j]);
		}
}

void solve() {
	cin >> n;
	if (n > 1e5) {
		f();
		return;
	}
	//else go for bruter approach
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v[x % 2][y % 2].pb (x, y);
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			solveSelf (v[i][j]);
	solveDiff (v[0][0], v[1][1]);
	solveDiff (v[0][1], v[1][0]);
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}