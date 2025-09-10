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
#include <unordered_set>
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
int n, a[N], x;
unordered_set <int> s;

void dfs (vi &dibbas, int cur) {
	if (cur > n)
		return;
	dibbas.pb (a[cur]);
	if (cur == n) {
		x = 0;
		for (auto j : dibbas)
			x ^= j;
		s.emplace (x);
	}
	dfs (dibbas, cur + 1);
	dibbas.pop_back();
	for (auto& cnt : dibbas) {
		cnt += a[cur];
		if (cur == n) {
			x = 0;
			for (auto j : dibbas)
				x ^= j;
			s.emplace (x);
		}
		dfs (dibbas, cur + 1);
		cnt -= a[cur];
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vi dibbas;
	dfs (dibbas, 1);
	cout << s.size();
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}