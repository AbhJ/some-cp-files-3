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
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)
#define all(x)       x.begin(), x.end()
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     2e6 + 10;
const int M    =     1e9 + 7;
int f[N], b[N];
int mul(int a, int b) {
	return (a * b) % M;
}
int add(int a, int b) {
	a += b;
	if (a >= M)
		a -= M;
	return a;
}
int sub(int a, int b) {
	return (a - b + M) % M;
}
int powM(int b, int p) {
	int r = 1;
	for (; p; b = b * b % M, p /= 2) {
		if (p & 1)
			r = r * b % M;
	}
	return r;
}
int invM(int x) {
	return powM(x, M - 2);
}
void binomialCoeff() {
	f[0] = b[0] = 1;
	rep(i, 1, N - 1) {
		f[i] = mul(f[i - 1], i);
		b[i] = powM(f[i], M - 2);
	}
}
int C(int n, int r) {
	assert(n < N); assert(r < N);
	if (r > n)return 0;
	return (f[n] * mul(b[r], b[n - r]) % M) % M;
}
int Com[61][61];
void solve() {
	Com[0][0] = 1;
	for (int i = 1; i <= 60; i++) {
		Com[i][0] = 1;
		for (int j = 1; j <= i; j++)Com[i][j] = Com[i - 1][j] + Com[i - 1][j - 1];
	}
	int a, b, k;
	cin >> a >> b >> k;
	while (a and b) {
		int cnt = Com[a + b - 1][b];
		if (cnt + 1 > k)
			cout << 'a', a--;
		else
			cout << 'b', b--, k -= cnt;
	}
	while (a--)
		cout << 'a';
	while (b--)
		cout << 'b';
}
int32_t main() {
	binomialCoeff();
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	int t; cin >> t;
	while (t--) {
		solve(); cout << "\n";
	}
	return 0;
}