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
int n, m;
set<int> s;

void solve() {
	cin >> n >> m;
	// the set contains the diagonals that we wanna fill
	// there are m diagonals we wanna fill
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		s.emplace ((y - x + n) % n);
	}
	for (int i = 0; s.size() != m; i++) {
		s.emplace (i);
	}
	cout << n * s.size() << "\n";
	for (int i = 0; i < n; i++) for (int dif : s) {
			int j = (i + dif) % n;
			cout << i + 1 << " " << j + 1 << "\n";
		}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}