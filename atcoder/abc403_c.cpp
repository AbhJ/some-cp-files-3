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
int n, m, q, ty, x, y;
bool allHave[N];
set<int> s[N];

void solve() {
	cin >> n >> m >> q;
	while (q--) {
		cin >> ty >> x;
		if (ty == 1) {
			cin >> y;
			s[x].emplace (y);
		}
		if (ty == 2) {
			allHave[x] = 1;
		}
		if (ty == 3) {
			cin >> y;
			if (allHave [x] or s[x].count (y))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}