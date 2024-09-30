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
string s;
int n, _map, _pie, _mapie;

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (i + 3 <= n and s.substr (i, 3) == "map")
			_map++;
		if (i + 3 <= n and s.substr (i, 3) == "pie")
			_pie++;
		if (i + 5 <= n and s.substr (i, 5) == "mapie")
			_mapie++;
	}
	cout << _map + _pie - _mapie;
	_map = _pie = _mapie = 0;
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