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
const int N    =     1e2 + 10;
string s[2][N];
int n;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[0][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> s[1][i];
		if (s[0][i] == s[1][i])
			continue;
		for (int j = 0; j < n; j++) if (s[0][i][j] != s[1][i][j]) {
				cout << i + 1 << " "  << j + 1;
				return;
			}
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}