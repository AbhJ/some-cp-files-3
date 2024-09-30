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

int n, m, k, F[N];

void solve() {
	cin >> n >> m >> k;
	int expected_sum = 0, average_increment_per_edge;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> F[i] >> F[i] >> F[i];
		expected_sum = add (expected_sum, F[i]);
	}
	for (int i = 0; i < k; i++) {
		// we can choose any edge out of totally C(n, 2) possible edges
		average_increment_per_edge = mul (expected_sum,
		                                  invM (C (n, 2)));
		ans = add (ans, average_increment_per_edge);
		expected_sum = add (expected_sum, mul (m,
		                                       invM (C (n, 2))));
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	binomialCoeff();
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}