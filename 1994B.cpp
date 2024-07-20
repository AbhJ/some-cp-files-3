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
string s, t;

void solve() {
	cin >> n >> s >> t;
	if (s[0] == '1') {
		cout << "YES";
		return;
	}
	if (t[0] == '1') {
		cout << "NO";
		return;
	}
	// both of them start with 0
	int cnt1 = 0, cnt2 = 0, pos1 = - 1, pos2 = - 1;
	for (int i = 0; i < n; i++) {
		cnt1 += s[i] == '1';
		cnt2 += t[i] == '1';
		if (s[i] == '1')
			pos1 = i;
		if (t[i] == '1') {
			pos2 = i;
			if (pos1 == - 1) {
				cout << "NO";
				return;
			}
		}
	}
	if (cnt2 != 0 and cnt1 == 0) {
		cout << "NO";
		return;
	}
	cout << "YES";
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