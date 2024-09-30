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
vi a;

void solve() {
	cin >> n;
	a.resize (n);
	for (auto &i : a)
		cin >> i;
	while (!is_sorted (a.begin(), a.end())) {
		int ops = 0;
		for (int i = 0; i < (int) a.size(); i++) {
			int cur = a[i];
			if (a[i] <= 9) {
				continue;
			}
			a.erase (a.begin() + i);
			if (cur > 9) {
				a.emplace (a.begin() + i, cur % 10);
				a.emplace (a.begin() + i, cur / 10);
			}
			else {
				a.emplace (a.begin() + i, cur);
			}
			ops++;
			break;
		}
		if (ops == 0) {
			cout << "NO";
			return;
		}
	}
	cout << "YES";
	a.clear();
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