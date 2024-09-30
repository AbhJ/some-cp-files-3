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
int n, a[N], till_now, b[N], koibar;
void solve() {
	cin >> n;
	multiset<int>s;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	till_now = *max_element(a, a + n--);
	s.erase(s.find(till_now));
	cout << till_now << " ";
	koibar = (int)log2(till_now);
	for(int i = 0; i < min(koibar, n); i++){
		int tmp = 0;
		for(int j : s){
			if((till_now | tmp) <= (till_now | j))
				tmp = j;
		}
		till_now |= tmp;
		cout << tmp << " ";
		s.erase(s.find(tmp));
	}
	for(int i = min(koibar, n); i < n; i++){
		cout << * s.begin() << " ";
		s.erase(s.begin());
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve(); cout << "\n";
	}
	return 0;
}
