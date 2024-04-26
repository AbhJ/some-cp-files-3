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
#include <iomanip>
#define int          long long int
#define double       long double
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
int n, a, x, y;
map<int, double> dp;

double f (int div) {
	// div means we are now solving for n / div
	if (div > n)
		return 0;
	if (dp.count (div))
		return dp[div];
	double lef = f (div * a) + x;
	double rig = 0.2 * (f (div * 2) + f (div * 3) + f (div * 4) + f (div * 5) + f (
	                        div * 6)) + 1.2 * y;
	return dp [div] = min (lef, rig);
}

void solve() {
	cin >> n >> a >> x >> y;
	cout << fixed << std::setprecision (9) << f (1);
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}