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
vvi v;
set<pii> s;

void solve() {
	cin >> n;
	v = vvi (n + 1);
	s.clear();
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
		v[a[i]].pb (i);
	}
	for (int i = 1; i < 2 * n; i++) {
		int A = a[i], B = a[i - 1];
		int A1 = v[A][0], A2 = v[A][1];
		int B1 = v[B][0], B2 = v[B][1];
		if (A2 - A1 == 1 or B2 - B1 == 1 or abs (A1 - B1) != 1 or abs (A2 - B2) != 1)
			continue;
		if (A > B)
			swap (A, B);
		if (s.count (mp (A, B)))
			continue;
		s.emplace (A, B);
	}
	cout << s.size();
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