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
#define mp          make_pair
#define pb          emplace_back
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
const int MOD  =     998244353;

int power (int a, int b) {
	int res = 1;
	a %= MOD;
	while (b > 0) {
		if (b % 2 == 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

int inv (int n) {
	return power (n, MOD - 2);
}

void ntt (vi& a, bool inv_flag) {
	int sz = a.size();
	for (int i = 1, j = 0; i < sz; i++) {
		int bit = sz >> 1;
		for (; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if (i < j) swap (a[i], a[j]);
	}
	for (int len = 2; len <= sz; len <<= 1) {
		int wlen = power (3, (MOD - 1) / len);
		if (inv_flag) wlen = inv (wlen);
		for (int i = 0; i < sz; i += len) {
			int w = 1;
			for (int j = 0; j < len / 2; j++) {
				int u = a[i + j], v = (a[i + j + len / 2] * w) % MOD;
				a[i + j] = (u + v) % MOD;
				a[i + j + len / 2] = (u - v + MOD) % MOD;
				w = (w * wlen) % MOD;
			}
		}
	}
	if (inv_flag) {
		int sz_inv = inv (sz);
		for (int& x : a) x = (x * sz_inv) % MOD;
	}
}

vi mul (vi a, vi b) {
	int sz = 1;
	while (sz < (int) (a.size() + b.size())) sz <<= 1;
	a.resize (sz);
	b.resize (sz);
	ntt (a, false);
	ntt (b, false);
	for (int i = 0; i < sz; i++) a[i] = (a[i] * b[i]) % MOD;
	ntt (a, true);
	while (a.size() > 1 && a.back() == 0) a.pop_back();
	return a;
}

vi get_poly (int l, int r) {
	if (l + 1 == r) return {l, 1};
	int mid = (l + r) / 2;
	return mul (get_poly (l, mid), get_poly (mid, r));
}

void solve() {
	int n, k;
	cin >> n >> k;
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact = (fact * i) % MOD;
	if ((n << 1) - k < 1 or (n << 1) - k > n) {
		cout << 0;
		return;
	}
	cout << (get_poly (0, n)[ (n << 1) - k] * inv (fact)) % MOD;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}