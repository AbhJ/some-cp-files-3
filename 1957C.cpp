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
const int M    =     1e9 + 7;

int add (int a, int b) {
	a += b;
	return (a >= M ? a - M : a);
}

int mul (int a, int b) {
	return (a * b) % M;
}

int sub (int a, int b) {
	return (a - b + M) % M;
}

int powM (int b, int p) {
	int r = 1;
	for (; p; b = mul (b, b), p >>= 1)
		if (p & 1)
			r = mul (r, b);
	return r;
}

int invM (int x) {
	return powM (x, M - 2);
}

int f[N], b[N];

void binomialCoeff() {
	f[0] = 1;
	for (int i = 1; i <= N - 1; i++)
		f[i] = mul (f[i - 1], i);
	b[N - 1] = powM (f[N - 1], M - 2);
	for (int i = N - 2; i >= 0; i--)
		b[i] = mul (b[i + 1], i + 1);
}

int C (int n, int r) {
	return (r > n ? 0LL : (f[n] * mul (b[r], b[n - r]) % M) % M);
}

int n, k, r[N], c[N], dp[N];

int h (int cnt) {
	if (cnt <= 1)
		return 1;
	if (cnt == 2)
		return 3;
	if (~dp[cnt])
		return dp[cnt];
	return dp[cnt] = add (mul (1, h (cnt - 1)), mul (mul (2, cnt - 1),
	                      h (cnt - 2)));
}

void solve() {
	cin >> n >> k;
	fill (dp, dp + 1 + n, - 1);
	set<int> s;
	for (int i = 0; i < k; i++) {
		cin >> r[i] >> c[i];
		s.emplace (r[i]);
		s.emplace (c[i]);
	}
	int cnt = n - s.size();
	cout << h (cnt);
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
