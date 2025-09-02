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
int n, k, u[N], v[N], s[N];
bool isRem[N];
vi a[N];
bool dfs (int cur, int p = - 1) {
	s[cur] = 1;
	int cnt = 0;
	for (auto nex : a[cur]) if (nex != p) {
			if (!dfs (nex, cur))
				return false;
			s[cur] += s[nex];
			cnt += !isRem[nex];
		}
	if (s[cur] < k) {
		return cnt < 2;
	}
	if (s[cur] > k) {
		return false;
	}
	if (cnt < 3) {
		isRem[cur] = true;
		s[cur] = 0;
	}
	return isRem[cur];
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n * k; i++) {
		cin >> u[i] >> v[i];
		a[u[i]].pb (v[i]);
		a[v[i]].pb (u[i]);
	}
	cout << (dfs (1) ? "Yes" : "No");
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}