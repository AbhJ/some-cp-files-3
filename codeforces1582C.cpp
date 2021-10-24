
/**
 * @author      : abhj
 * @created     : Sunday Oct 24, 2021 16:04:12 IST
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

#define watch(x) cerr << (#x) << " is " << (x) << "\n";
void debug (string t) {
	cerr << t;
}
void debug (int t) {
	cerr << t;
}
void debug (double t) {
	cerr << t;
}
void debug (char t) {
	cerr << t;
}
template <class T> void debug (vector <T> v);
template <class T> void debug (vector <T> v) {
	cerr << "[ ";
	for (T i : v) {
		debug (i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T> void debug (set <T> v);
template <class T> void debug (set <T> v) {
	cerr << "[ ";
	for (T i : v) {
		debug (i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T> void debug (multiset <T> v);
template <class T> void debug (multiset <T> v) {
	cerr << "[ ";
	for (T i : v) {
		debug (i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V> void debug (pair <T, V> p);
template <class T, class V> void debug (pair <T, V> p) {
	cerr << "{";
	debug (p.F);
	cerr << ",";
	debug (p.S);
	cerr << "}";
}
template <class T, class V> void debug (map <T, V> v);
template <class T, class V> void debug (map <T, V> v) {
	cerr << "[ ";
	for (auto i : v) {
		debug (i);
		cerr << " ";
	}
	cerr << "]";
}

string s;
int n;

void solve() {
	cin >> n >> s;
	int l = 0, r = n - 1, cntLef = 0, cntRig = 0, isLef = 1, isRig = 1;
	while (l <= r) {
		char ch;
		if (s[l] == s[r])
			l++, r--;
		else {
			ch = s[l];
			cntLef++;
			int lef = l + 1, rig = r;
			while (lef <= rig) {
				if (s[lef] == s[rig])
					lef++, rig--;
				else if (s[lef] == ch)
					cntLef++, lef++;
				else if (s[rig] == ch)
					cntLef++, rig--;
				else {
					isLef = 0;
					break;
				}
			}
			ch = s[r];
			cntRig++;
			lef = l;
			rig = r - 1;
			while (lef <= rig) {
				if (s[lef] == s[rig])
					lef++, rig--;
				else if (s[lef] == ch)
					cntRig++, lef++;
				else if (s[rig] == ch)
					cntRig++, rig--;
				else {
					isRig = 0;
					break;
				}
			}
			l = r + 1;
		}
	}
	if (isLef != 0 and isRig != 0)
		cout << min (cntLef, cntRig);
	else if (isLef == 0 and isRig == 0)
		cout << - 1;
	else if (isLef)
		cout << cntLef;
	else if (isRig)
		cout << cntRig;
	else
		assert (0);
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}
