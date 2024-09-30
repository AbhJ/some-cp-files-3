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
int n, a[N];

void solve() {
	cin >> n;
	map<int, int> fr;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		fr[a[i]]++;
	}
	vpii v;
	for (auto [x, f] : fr) {
		v.pb (f, x);
	}
	sort (v.rbegin(), v.rend());
	for (auto [f, x] : v) {
		if (f & 1) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
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