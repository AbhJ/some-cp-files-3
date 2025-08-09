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
const int N    =     1e6 + 10;
int n, q;
vi prime_vector_sieve() {
	vi prime (N);
	for (int i = 2; i < N; ++i)
		if (prime[i] == 0) {
			for (int j = i; j < N; j += i)
				prime[j]++;
		}
	return prime;
}

void solve() {
	vi a = prime_vector_sieve();
	vi b (N);
	for (int i = 2; i < N; i++) {
		b[i] = b[i - 1];
		if (a[i] == 2)
			b[i] = i * i;
	}
	cin >> q;
	while (q--) {
		cin >> n;
		cout << b[sqrt (n)] << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}