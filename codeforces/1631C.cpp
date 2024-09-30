
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Thursday May 19, 2022 18:10:01 IST
 * @filename    : a.cpp
 */

#include "bits/stdc++.h"
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

int n, k;

void solve() {
	cin >> n >> k;
	vpii v;
	int cnt = 0;
	if (k == 0) {
		set<int>s;
		for (int i = 0; i < n - 1; i++) {
			if (s.count (i))
				continue;
			s.emplace (i);
			if (s.count (i ^ (n - 1)))
				continue;
			s.emplace (i ^ (n - 1));
			v.pb (i, i ^ (n - 1));
		}
	}
	else if (k == n - 1) {
		v.pb (n - 2, n - 1); //gives n - 1
		v.pb (1, n - 3);    //gives 1
		v.pb (0, 2);
		set<int>s {0, 1, 2, n - 3, n - 2, n - 1};
		for (int i = 0; i < n - 1; i++) {
			if (s.count (i))
				continue;
			s.emplace (i);
			if (s.count (i ^ (n - 1)))
				continue;
			s.emplace (i ^ (n - 1));
			v.pb (i, i ^ (n - 1));
		}
	}
	else {
		v.pb (0, k ^ (n - 1)); //gives 0
		v.pb (k, n - 1);     //gives k
		set<int>s {0, k, k ^ (n - 1), n - 1};
		for (int i = 0; i < n - 1; i++) {
			if (s.count (i))
				continue;
			s.emplace (i);
			if (s.count (i ^ (n - 1)))
				continue;
			s.emplace (i ^ (n - 1));
			v.pb (i, i ^ (n - 1));
		}
	}
	set<int>s;
	for (int i = 0; i < v.size(); i++) {
		if (s.count (v[i].F) or v[i].F < 0 or v[i].F > n - 1) {
			cout << - 1;
			return;
		}
		if (s.count (v[i].S) or v[i].S < 0 or v[i].S > n - 1) {
			cout << - 1;
			return;
		}
		s.emplace (v[i].F);
		s.emplace (v[i].S);
		cnt += v[i].F & v[i].S;
	}
	if (cnt != k or s.size() != n) {
		cout << - 1;
		return;
	}
	for (auto i : v)
		cout << i.F << " " << i.S << "\n";
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
