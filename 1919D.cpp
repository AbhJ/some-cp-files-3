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
set <int> biggerThanCurr;

bool check (int posi, int val) {
	if (posi == - 1 or posi == n)
		return false;
	return a[posi] == val;
}

void solve2() {
	biggerThanCurr.clear();
	biggerThanCurr.emplace (- 1);
	biggerThanCurr.emplace (n);
	vvi pos (n);
	for (int i = 1; i <= n; i++) {
		pos [a[i]]. pb (i);
	}
	int maxi = *max_element (a + 1, a + n + 1);
	for (int cur = maxi; cur >= 0; cur--) {
		for (int posi : pos [cur]) {
			// now we handle multiple 1s at a time so basically for every one
			// we check the left and right position of 0 directly
			auto nex = biggerThanCurr.lower_bound (posi);
			auto pre = prev (nex);
			// position of cur is posi
			// now either of pre or nex must have cur + 1
			if (check (*pre, cur + 1) or check (*nex, cur + 1) or cur == maxi)
				continue;
			else {
				cout << "NO";
				return;
			}
		}
		for (int posi : pos[cur])
			biggerThanCurr.emplace (posi);
	}
	if (pos[0].size() == 1)
		cout << "YES";
	else cout << "NO";
}

void solve() {
	cin >> n;
	int ops = 0;
	//pq contains the pair of heights and initial positions
	set <pii> pq;
	// s contains initial posi
	set <int> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pq.emplace (a[i], i);
		s.emplace (i);
	}
	// every step we remove the largest and its sibling
	while (pq.size() > 1) {
		auto larg_it = prev (pq.end());
		int hei = larg_it -> F;
		int F = 0;
		while (larg_it -> F == hei) {
			if (++ops > 5e6) {
				solve2();
				return;
			}
			int posi = larg_it -> S, pre = - 1, nex = - 1;
			auto it_larg = s.lower_bound (posi);
			if (it_larg != s.begin())
				pre = *prev (it_larg);
			if (it_larg != prev (s.end()))
				nex = *next (it_larg);
			if (pre != - 1 and a[pre] == a[posi] - 1) {
				// mini is the pre
				pq.erase (larg_it);
				s.erase (it_larg);
				F = 1;
				if (larg_it == pq.begin())
					break;
				larg_it = prev (larg_it);
				break;
				// larg is deleted
			}
			else if (nex != - 1 and a[nex] == a[posi] - 1) {
				// mini is the nex
				pq.erase (larg_it);
				s.erase (it_larg);
				F = 1;
				if (larg_it == pq.begin())
					break;
				larg_it = prev (larg_it);
				break;
				// larg is deleted
			}
			else {
				if (larg_it == pq.begin())
					break;
				larg_it = prev (larg_it);
			}
		}
		if (F == 0) {
			cout << "NO";
			return;
		}
	}
	if (pq.size() == 1 and pq.begin() -> F != 0)
		cout << "NO";
	else
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