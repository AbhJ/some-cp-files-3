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
int n;
vi pre, suf;

vi calci_pre (vi &A) {
	vector<bool> b (n + 1);
	int mex = 0;
	vi pre (n);
	for (int i = 0; i < n; i++) {
		b[A[i]] = true;
		while (b[mex] == true) {
			mex++;
		}
		pre[i] = mex;
	}
	return pre;
}

void solve() {
	cin >> n;
	vi a (n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vi pre = calci_pre (a);
	reverse (a.begin(), a.end());
	vi suf = calci_pre (a);
	reverse (suf.begin(), suf.end());
	for (int i = 0; i < n - 1; i++) {
		if (pre[i] == suf[i + 1]) {
			cout << "2\n1 ";
			cout << i + 1 << "\n" << i + 2 << " " << n;
			return;
		}
	}
	cout << - 1;
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