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
int n, a[N];
set<int>s;
vpii ans;
void solve() {
	cin >> n;
	s.clear();
	ans.clear();
	vi foun (n, - 1);
	set <int> posi;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		posi.emplace (i);
	}
	for (int mod = n - 1; mod != 0; mod--) {
		// for every mod we just need one pair
		for (auto i : posi) {
			if (~foun[a[i] % mod]) {
				// we got the pair
				ans.pb (foun[a[i] % mod], i);
				posi.erase (i);
				foun = vi (n, - 1);
				break;
				//guaranteed to hit this every time we iterate for (auto i: posi)
				//coz pigeonhole principle
			}
			foun[a[i] % mod] = i;
		}
	}
	if (ans.empty() and n != 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (auto i = ans.rbegin(); i != ans.rend(); i = next (i)) {
		cout << i -> F + 1 << " " << i -> S + 1 << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}