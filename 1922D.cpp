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
#include <cassert>
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
int n, a[N], d[N];

void solve() {
	cin >> n;
	set<int> alive, can_die;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		alive.emplace (i);
		can_die.emplace (i);
	}
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	for (int i = 0; i < n; i++) {
		int deaths = 0;
		set<int> can_die_new, to_erase;
		for (auto mon : can_die) if (alive.count (mon)) {
				auto it = alive.find (mon);
				int pos_left = (it == alive.begin() ? - 1 : *prev (it)), pos_right = (it == prev (alive.end()) ? - 1 : *next (it));
				int attack = (pos_left != - 1 ? a[pos_left] : 0) + (pos_right != - 1 ? a[pos_right] : 0);
				if (attack > d[mon]) {
					// mon dies
					if (pos_left != - 1)
						can_die_new.emplace (pos_left);
					if (pos_right != - 1)
						can_die_new .emplace (pos_right);
					to_erase.emplace (mon);
				}
			}
		for (auto j : to_erase)
			alive.erase (j);
		swap (can_die_new, can_die);
		cout << to_erase.size() << " ";
	}
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