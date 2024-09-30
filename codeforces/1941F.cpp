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
int n, m, k;
vi v, diff;
multiset<int> s1;
multiset<int> s2;
void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back (x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		s1.emplace (x);
	}
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		s2.emplace (x);
	}
	int ma = 0, cnt = 0, low = 0, high = 0;
	for (int i = 1; i < n; i++) {
		diff.pb (v[i] - v[i - 1]);
		if (v[i] - v[i - 1] > ma) {
			ma = v[i] - v[i - 1];
			low = v[i - 1];
			high = v[i];
			cnt = 0;
		}
		else if (v[i] - v[i - 1] == ma)
			cnt++;
	}
	if (cnt > 0) {
		cout << ma;
		v.clear();
		diff.clear();
		s1.clear();
		s2.clear();
		return;
	}
	int mid = (low + high) / 2;
	vector<int> ans;
	for (auto i : s1) {
		int maxi1 = mid - i;
		int num1 = -1, num2 = -1;
		auto it1 = s2.lower_bound (maxi1);
		if (it1 == s2.end()) {
			num2 = *--it1;
		}
		else {
			num1 = *it1;
			if (it1 != s2.begin()) {
				num2 = *--it1;
			}
		}
		if (num1 != -1) {
			int maxi2 = num1 + i;
			int mnum1 = max (abs (maxi2 - low), abs (high - maxi2));
			ans.pb (mnum1);
		}
		if (num2 != -1) {
			int maxi2 = num2 + i;
			int mnum1 = max (abs (maxi2 - low), abs (high - maxi2));
			ans.pb (mnum1);
		}
	}
	int mi = *min_element (ans.begin(), ans.end());
	int maxi = ma;
	if (ma <= mi) {
		cout << ma;
		v.clear();
		diff.clear();
		s1.clear();
		s2.clear();
		return;
	}
	for (auto i : diff) if (i != maxi)
			mi = max (i, mi);
	cout << mi;
	v.clear();
	diff.clear();
	s1.clear();
	s2.clear();
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