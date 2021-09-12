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
int s, t, cnt;
void solve() {
	cin >> s >> t;
	for (int i = 0; i <= s; i++) {
		for (int j = 0; j <= s - i; j++) {
			for (int k = 0; k <= s - i - j; k++) {
				if (i * j * k <= t)
					cnt++;
			}
		}
	}
	cout << cnt;
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}