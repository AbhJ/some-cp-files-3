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
int n, q, curBox[N], box[N], ty, x, y, pig[N];

void solve() {
	cin >> n >> q;
	iota (pig + 1, pig + 1 + n, 1LL);
	iota (curBox + 1, curBox + 1 + n, 1LL);
	iota (box + 1, box + 1 + n, 1LL);
	while (q--) {
		cin >> ty >> x;
		if (ty == 1) {
			cin >> y;
			pig[x] = curBox[y];
		}
		if (ty == 2) {
			cin >> y;
			swap (curBox[x], curBox[y]);
			swap (box[curBox[x]], box[curBox[y]]);
		}
		if (ty == 3) {
			cout << box[pig[x]] << "\n";
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}