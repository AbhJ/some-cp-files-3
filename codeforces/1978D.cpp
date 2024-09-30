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
int n, a[N], ma, pr, c;
void solve() {
	ma = 0, pr = 0;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > a[ma])
			ma = i;
	}
	for (int i = 0; i < n; i++) {
		pr += a[i];
		if (pr + c < a[ma]) {
			// include ma as well
			cout << i + 1;
		}
		else if (i == ma and a[i] > a[0] + c)
			cout << 0;
		else cout << i;
		cout << " ";
	}
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