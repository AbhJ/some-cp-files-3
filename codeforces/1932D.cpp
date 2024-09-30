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
#include <sstream>
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
int n;
char trump;
map <char, set <char>> m;
vector<string> leftover;
string ans, s;

void solve() {
	ans.clear();
	leftover.clear();
	m.clear();
	cin >> n >> trump;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> s;
		m[s[1]].emplace (s[0]);
	}
	// non trump beats non trump
	for (auto &p : m) if ((char)p.F != trump) {
			char suit = p.F;
			set <char> nums = p.S;
			while (nums.size() > 1) {
				string s;
				auto lef = nums.begin();
				s += *lef;
				s += suit;
				nums.erase (lef);
				auto rig = prev (nums.end());
				s += ' ';
				s += *rig;
				s += suit;
				nums.erase (rig);
				ans += s + '\n';
			}
			if (nums.size() == 1) {
				string s;
				s += (char) * nums.begin();
				s += (char)suit;
				leftover.pb (s);
			}
		}
	if (leftover.size() > m[trump].size()) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	// trump beats non trump
	for (string i : leftover) {
		auto tru = m[trump].begin();
		string s;
		s += i;
		s += ' ';
		s += *tru;
		s += trump;
		m[trump].erase (tru);
		ans += s + '\n';
	}
	// trump beats trump
	while (!m[trump].empty()) {
		auto lef = m[trump].begin();
		string s;
		s += *lef;
		s += trump;
		m[trump].erase (lef);
		auto rig = prev (m[trump].end());
		s += ' ';
		s += *rig;
		s += trump;
		m[trump].erase (rig);
		ans += s + '\n';
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}