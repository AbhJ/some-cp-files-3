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
int n, k, cnto, cntq, cur;
string s, ini;

void solve() {
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		if (i != 0 and s[i - 1] == 'o' and s[i] == '?')
			s[i] = '.';
		if (i != n - 1 and s[i + 1] == 'o' and s[i] == '?')
			s[i] = '.';
		if (s[i] == 'o')
			cnto++;
		if (s[i] == '?')
			cntq++;
	}
	if (cnto + cntq == k) {
		for (int i = 0; i < n; i++)
			if (s[i] == '?')
				s[i] = 'o';
	}
	else if (cnto == k) {
		for (int i = 0; i < n; i++)
			if (s[i] == '?')
				s[i] = '.';
	}
	else {
		ini = s;
		for (int i = 0; i <= n; i++) {
			if (i != n and s[i] == '?')
				cur++;
			else {
				// if even after solving for odd lengths of consecutive ?,
				// we have bandwidth to convert ? to o for even lengths given k
				// o.o.o shall be pattern for all odd lengths of consecutive ?
				if (cur & 1)
					for (int j = i - cur; j <= i - 1; j++)
						if ((j ^ i) & 1 ^ 1)
							s[j] = '.';
						else
							s[j] = 'o', cnto++;
				else
					cnto += (cur >> 1);
				cur = 0;
			}
		}
		if (cnto > k)
			s = ini;
	}
	cout << s;
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}