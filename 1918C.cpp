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
int a, b, r, ans;

void solve() {
	cin >> a >> b >> r;
	if (a < b)
		swap (a, b);
	for (int bit = 63; ~bit; bit--) {
		if ((a & (1LL << bit)) == (b & (1LL << bit))) {
			continue;
		}
		if ((1LL << bit) <= r) {
			// a > b so no need to check for the other case
			if (abs (ans + (a & (1LL << bit)) - (b & (1LL << bit))) > abs (ans - (a &
			        (1LL << bit)) + (b & (1LL << bit)))) {
				ans = abs (ans - (a & (1LL << bit)) + (b & (1LL << bit)));
				r -= (1LL << bit);
			}
			else
				ans += (a & (1LL << bit)) - (b & (1LL << bit));
		}
		else
			ans += (a & (1LL << bit)) - (b & (1LL << bit));
	}
	cout << abs (ans);
	ans = 0;
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