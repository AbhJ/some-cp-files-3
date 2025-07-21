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
const int N    =     3e6 + 10;
int n, A, B, C, D, ans;
const int M    =     998244353;

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

int Com (int n, int r) {
	return (r > n ? 0LL : (f[n] * mul (b[r], b[n - r]) % M) % M);
}

void solve() {
	cin >> A >> B >> C >> D;
	binomialCoeff();
	for (int i = A; i <= A + B; i++)
		ans = add (mul (Com (i - 1, A - 1), Com (A + B + C + D - i, C)), ans);
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}