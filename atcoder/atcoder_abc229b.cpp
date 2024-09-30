/**
 * @author      : abhj
 * @created     : Saturday Nov 27, 2021 17:37:24 IST
 * @filename    : b.cpp
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

string a, b;
int count_carry (string a, string b) {
	// Initialize the value of carry to 0
	int carry = 0;
	// Counts the number of carry operations
	int count = 0;
	// Initialize len_a and len_b with the sizes of strings
	int len_a = a.length(), len_b = b.length();
	while (len_a != 0 || len_b != 0) {
		// Assigning the ascii value of the character
		int x = 0, y = 0;
		if (len_a > 0) {
			x = a[len_a - 1] - '0';
			len_a--;
		}
		if (len_b > 0) {
			y = b[len_b - 1] - '0';
			len_b--;
		}
		// Add both numbers/digits
		int sum = x + y + carry;
		// If sum > 0, increment count
		// and set carry to 1
		if (sum >= 10) {
			carry = 1;
			count++;
		}
		// Else, set carry to 0
		else
			carry = 0;
	}
	return count;
}

void solve() {
	cin >> a >> b;
	cout << (count_carry (a, b) ? "Hard" : "Easy");
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}

