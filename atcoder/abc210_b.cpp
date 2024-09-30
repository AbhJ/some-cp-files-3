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
int n; string s;
void solve() {
	cin >> n >> s;
	int x = 0, y = 0, cnt = 0;
	for (auto &i : s) {
		if (cnt == 0)
			x |= (i == '1');
		else
			y |= (i == '1');
		if (x == 1) {
			cout << "Takahashi";
			return;
		}
		if (y == 1) {
			cout << "Aoki";
			return;
		}
		cnt ^= 1;
	}
	assert(0);
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}