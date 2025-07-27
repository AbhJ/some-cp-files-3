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
int n, ty, strId, ans, yStringId;
string s;
int t[N][26];
bool isPartOfX[N], visyStringId[N];
vi stringsOfYAtNode[N];
void insertX (string s) {
	int node = 0;
	for (char c : s) {
		if (t[node][c - 'a'] == 0) {
			t[node][c - 'a'] = ++strId;
		}
		node = t[node][c - 'a'];
	}
	isPartOfX[node] = true;
	for (auto id : stringsOfYAtNode[node])
		if (!visyStringId[id]) {
			visyStringId[id] = true;
			ans--;
		}
	stringsOfYAtNode[node].clear();
}
void insertY (string s) {
	// if any pref has been inserted as part of X, answer reduces overall by 1
	// by default we assume it won't be such a case
	ans++;
	yStringId++;
	int node = 0;
	bool hasPrefixInX = false;
	for (char c : s) {
		if (t[node][c - 'a'] == 0) {
			t[node][c - 'a'] = ++strId;
		}
		node = t[node][c - 'a'];
		if (isPartOfX[node] and !hasPrefixInX)
			hasPrefixInX = true;
		stringsOfYAtNode[node].pb (yStringId);
	}
	if (hasPrefixInX) {
		visyStringId[yStringId] = true;
		ans--;
	}
}

void solve() {
	cin >> n;
	while (n--) {
		cin >> ty >> s;
		if (ty == 1)
			insertX (s);
		else
			insertY (s);
		cout << ans << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}