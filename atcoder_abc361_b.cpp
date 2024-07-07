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
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;

int a[6], b[6];

void solve() {
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 0; i < 6; i++) {
		cin >> b[i];
	}
	cout << (((a[3] > b[0]) and
	          (a[0] < b[3]) and
	          (a[4] > b[1]) and
	          (a[1] < b[4]) and
	          (a[5] > b[2]) and
	          (a[2] < b[5])) ? "Yes" : "No");
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}