
/**
 * @author      : abhj
 * @created     : Saturday Sep 18, 2021 17:42:41 IST
 * @filename    : c.cpp
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

string s, S[N];
int n;

static bool cmp (string s1, string s2) {
	if (s1.length() == 0)
		return 1;
	if (s2.length() == 0)
		return 0;
	if (s1[0] == s2[0]) {
		string S1 = s1.substr (1);
		string S2 = s2.substr (1);
		return cmp (S1, S2);
	}
	int fir = s.find (s1[0]);
	int sec = s.find (s2[0]);
	return fir < sec;
}
void solve() {
	cin >> s >> n;
	for (int i = 0; i < n; i++)
		cin >> S[i];
	sort (S, S + n, cmp);
	for (int i = 0; i < n; i++)
		cout << S[i] << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
