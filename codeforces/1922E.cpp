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

int x;

// we store the min and max of the arr in the first two entries
tuple <int, int, vi> arr (int x) {
	if (x == 0)
		return make_tuple (0, 0, vi (- 1));
	if (x == 1)
		return make_tuple (0, 0, vi());
	// if x is odd we solve for x - 1 and add the new smallest element to end
	if (x & 1) {
		auto tmp = arr (x - 1);
		int mi = get<0> (tmp);
		auto new_arr = get<2> (tmp);
		new_arr.pb (mi - 1);
		assert (mi > - 1e9);
		return make_tuple (mi - 1, get<1> (tmp), new_arr);
	}
	// if x is even we solve for x / 2 and add the new largest element to end
	auto tmp = arr (x / 2);
	int ma = get<1> (tmp);;
	auto new_arr = get<2> (tmp);
	new_arr.pb (ma + 1);
	assert (ma < 1e9);
	return make_tuple (get<0> (tmp), ma + 1, new_arr);
}

void solve() {
	cin >> x;
	vi ans = get<2> (arr (x));
	if (ans == vi {- 1}) {
		cout << - 1;
		return;
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i << " ";
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