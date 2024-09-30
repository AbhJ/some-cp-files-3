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

int n, a[N], ans;

map <int, vector<int>> factors;

vi fact (int n) {
	vi v;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			v.pb (i);
			if (i * i != n)
				v.pb (n / i);
		}
	}
	return v;
}

void solve() {
	cin >> n;
	if (factors.count (n) == 0)
		factors[n] = fact (n);
	vi factors_of_n = factors[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vvi parted_a (n);
	for (int k : factors_of_n) {
		if (k == 1) {
			int mi = *min_element (a, a + n);
			int gcd = 0;
			for (int i = 0; i < n; i++) {
				gcd = std::gcd (a[i] - mi, gcd);
			}
			if (gcd != 1)
				ans++;
			continue;
		}
		int F = 0;
		for (int i = 0; i < n; i++) {
			parted_a[i % k].pb (a[i]);
		}
		int gcd = 0;
		for (vi &parted_a_vector : parted_a) {
			int mi = *min_element (parted_a_vector.begin(), parted_a_vector.end());
			for (auto &i : parted_a_vector) {
				gcd = std::gcd (i - mi, gcd);
			}
			if (parted_a_vector.size() == n) {
				ans++;
				F = 1;
				break;
			}
		}
		if (F == 0 and gcd != 1) {
			ans++;
		}
		for (int i = 0; i < n; i++) {
			parted_a[i % k].clear();
		}
	}
	cout << ans;
	ans = 0;
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