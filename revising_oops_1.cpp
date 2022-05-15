
/**
 * @author      : abhj (Abhijay Mitra)
 * @created     : Sunday May 15, 2022 12:16:05 IST
 * @filename    : a.cpp
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

class Car {
	int val;
	void beep() {
		cout << "Beep Beep!!!\n";
	}
public:
	int count_beeps;
	Car (int count) {
		count_beeps = count;
	}
	void honk() {
		for (int i = 0; i < count_beeps; i++) {
			cout << i + 1 << ": ";
			beep();
		}
	}
};

void solve() {
	Car mercy (2);
	mercy.honk();
	mercy.count_beeps = 4;
	mercy.honk();
}

int32_t main() {
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	solve();
	return 0;
}
