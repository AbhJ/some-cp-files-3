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
const int N    =     2e3 + 10;
int n, m, x, r[N], rig, lef;
vi unk;
char c[N];

void solve() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> r[i] >> c[i];
	}
	set<int> s;
	s.emplace (x - 1);
	for (int i = 0; i < m; i++) {
		if (c[i] == '0')
			rig += r[i];
		if (c[i] == '1')
			lef += r[i];
		if (c[i] == '?') {
			set<int> _s;
			for (auto j : s) {
				_s.emplace ((j + r[i]) % n);
				_s.emplace ((j + n - r[i]) % n);
			}
			swap (_s, s);
		}
	}
	cout << s.size() << "\n";
	vi v;
	for (auto i : s) {
		v.pb (((i - lef + rig + n * (int) 1e15) % n) + 1);
	}
	sort (v.begin(), v.end());
	for (auto i : v) {
		cout << i << " ";
	}
	lef = rig = 0;
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