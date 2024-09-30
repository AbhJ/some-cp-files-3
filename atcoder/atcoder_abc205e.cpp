#include "bits/stdc++.h"
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
int add(int a, int b) {
	a += b;
	return (a >= M ? a - M : a);
}
int mul(int a, int b) {
	return (a * b) % M;
}
int sub(int a, int b) {
	return (a - b + M) % M;
}
int powM(int b, int p) {
	int r = 1;
	for (; p; b = mul(b, b), p >>= 1)
		if (p & 1)
			r = mul(r, b);
	return r;
}
int invM(int x) {
	return powM(x, M - 2);
}
int f[N], b[N];
void binomialCoeff() {
	f[0] = 1;
	for (int i = 1; i <= N - 1; i++)
		f[i] = mul(f[i - 1], i);
	b[N - 1] = powM(f[N - 1], M - 2);
	for (int i = N - 2; i >= 0; i--)
		b[i] = mul(b[i + 1], i + 1);
}
int C(int n, int r) {
	return (r > n ? 0LL : (f[n] * mul(b[r], b[n - r]) % M) % M);
}
int n, m, k, ans;
void solve() {
	cin >> n >> m >> k;
	// black balls can be from i - k to m
	// - k - 1, k + 1 	m, n
	if (n < k + 1)
		cout << C(n + m, m);
	else if (n > m + k)
		cout << 0;
	else
		cout << sub(C(n + m, m), C(n + m, m + k + 1));
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	binomialCoeff();
	solve(); return 0;
	return 0;
}