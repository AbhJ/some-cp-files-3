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
string s;

void solve() {
	cin >> n >> s;
	string le, di;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			di += s[i];
			if (!le.empty()) {
				cout << "NO";
				return;
			}
		}
		else
			le += s[i];
	}
	cout << (is_sorted (le.begin(), le.end())
	         and is_sorted (di.begin(), di.end()) ? "YES" : "NO");
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