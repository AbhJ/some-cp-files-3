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

int n, k;
vi a;

void dfs (int i, int rem) {
	if (i == n) {
		if (rem % n == 0) {
			a.pb (rem / n);
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << "\n";
			a.pop_back();
		}
		return;
	}
	int m = rem / i;
	for (int v = 0; v <= m; v++) {
		a.pb (v);
		dfs (i + 1, rem - v * i);
		a.pop_back();
	}
}

void solve() {
	cin >> n >> k;
	dfs (1, k);
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}