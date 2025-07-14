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
//https://youtu.be/Tx1KfesO1rg reference
int n, a[N], cnt;
string s;

void solve() {
	cin >> n >> s;
	// zeroes [l][r] = r - l + 1 - ones [l][r]
	// ones outside [l][r] = total ones - ones [l][r]
	// we need to minimize cost = total ones + r - l + 1 - 2 * ones [l][r]
	// maximize 2 * ones [l][r] - (r - l + 1)
	// answer would be total ones - the max derived quantity
	// perform kadane on array a
	s = '#' + s;
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i] == '0' ? - 1 : 1;
		cnt += s[i] == '1';
	}
	int ma = 0, cu = 0;
	for (int i = 1; i <= n; i++) {
		cu += a[i];
		if (cu < 0)
			cu = 0;
		ma = max (cu, ma);
	}
	cout << cnt - ma;
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