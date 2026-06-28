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
int n;
string s;

void solve() {
	cin >> n >> s;
	vi f (3);
	f[0] = 1;
	int ans = (n * (n + 1)) / 2, cos = 0, cnt = 0;
	char las = s[0];
	for (auto c : s) {
		if (c == '0')
			cos += 1;
		else
			cos += 2;
		if (c != las) {
			cnt++;
			las = c;
		}
		else {
			cnt = 1;
		}
		ans -= f[cos %= 3];
		f[cos]++;
		ans -= (cnt - 1) / 2;
	}
	cout << ans;
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