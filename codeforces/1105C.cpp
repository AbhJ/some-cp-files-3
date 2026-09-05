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
int n, l, r, ans;
vi dp [N];

void solve() {
	cin >> n >> l >> r;
	vi c{r / 3 - (l - 1) / 3, (r + 2) / 3 - (l + 1) / 3, (r + 1) / 3 - l / 3};
	// if there are c0 number of threes we are choosing
	dp[0] = c;
	for (int i = 1; i < n; i++) {
		dp[i].resize (3);
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				dp[i][k] = add (mul (dp[i - 1][j], c[ (6 + k - j) % 3]), dp[i][k]);
				// if (k == 0 and i == 1)
				// 	cout << j << " " << (6 + k - j) % 3 << "\n";
			}
			// if (n == i + 1)
			// 	ans = add (dp[i][k], ans);
		}
	}
	cout << dp[n - 1][0];
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}