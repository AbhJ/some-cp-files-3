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
const int N    =     5e2 + 10;
int n, a[N][N], cnt;
vvi v;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int ty = 1; ty <= 2; ty++) {
			vi V;
			V.pb (ty);
			V.pb (i + 1);
			for (int j = 0; j < n; j++) {
				if (ty == 1) {
					a[i][j] = n - j;
				}
				else {
					a[j][i] = n - j;
				}
				V.pb (n - j);
			}
			v.pb (V);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cnt += a[i][j];
		}
	cout << cnt << " " << (int) v.size() << "\n";
	for (auto V : v) {
		for (auto j : V) {
			cout << j << " ";
		}
		cout << "\n";
	}
	v.clear();
	cnt = 0;
}
int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}