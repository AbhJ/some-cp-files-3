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
#include <random>
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
const int N    =     2e3 + 10;
int n, l, ans, maxAns;
vpii a;
bool cmpB (pii x, pii y) {
	//sort by b
	if (x.S != y.S)
		return x.S < y.S;
	return x.F < y.F;
}

void solve() {
	cin >> n >> l;
	a.resize (n);
	for (auto &[A, B] : a) {
		cin >> A >> B;
	}
	sort (a.begin(), a.end(), cmpB);
	for (int i = 0; i < n; i++) {
		auto [A1, B1] = a[i];
		priority_queue <int> heap_of_a;
		int sum_of_a = 0;
		for (int j = i; j < n; j++) {
			auto [A2, B2] = a[j];
			heap_of_a.emplace (A2);
			sum_of_a += A2;
			while (sum_of_a != 0 and sum_of_a + B2 - B1 > l) {
				int biggest_a = heap_of_a.top();
				heap_of_a.pop();
				sum_of_a -= biggest_a;
			}
			ans = max (ans, (int) heap_of_a.size());
		}
	}
	cout << ans;
	ans = 0;
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