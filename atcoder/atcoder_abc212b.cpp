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
string s;
void solve() {
	cin >> s;
	char last = (char)('z' + 1);
	int F = 0;
	for (auto i : s) {
		if (last == (char)('z' + 1)) {
		}
		else {
			if ((i - '0') == ((last - '0') + 1) % 10) {

			}
			else {
				F = 1;
			}
		}
		last = i;
	}
	if (F == 0) {
		cout << "Weak";
		return;
	}
	if (*min_element(s.begin(), s.end()) == *max_element(s.begin(), s.end()) and F != 0)
		F = 0;
	cout << (F ? "Strong" : "Weak");
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve(); return 0;
	return 0;
}