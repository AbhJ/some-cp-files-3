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
int n, c, k, cnt, mostFreq;
void solve() {
	cin >> n >> c;
	k = c;
	vector <int> f (c + 1);
	for (int i = 0; i < n; i++) {
		cin >> c;
		f[c]++;
		if (f[c] > f[mostFreq])
			mostFreq = c;
	}
	for (int i = 1; i <= k; i++) {
		cnt += (f[i] >= f[mostFreq] - 1);
	}
	cout << cnt;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}