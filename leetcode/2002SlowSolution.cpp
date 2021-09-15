#include <ctime>
#include <iostream>
#include <random>
class Solution {
public:
	int maxProduct (string s) {
		int n = s.length(), ans = 0;
		function <int (string&)> isPal = [&] (string & s) {
			string t = s;
			reverse (t.begin(), t.end());
			return s == t;
		};
		function <int (string&, string&)> f = [&] (string & lef, string & rig) -> int {
			if (isPal (lef) == 0 or isPal (rig) == 0)
				return 0;
			return lef.length() * rig.length();
		};
		mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
		int siz = 2 * pow (3, n) / 3;
		for (int z = 0; z < 9e4; z++) {
			int m = uniform_int_distribution<int> (0, siz) (rng), cnt = 0;
			string lef, rig;
			while (m != 0) {
				int i = m % 3;
				m /= 3;
				if (i == 1)
					lef += s[cnt];
				if (i == 2)
					rig += s[cnt];
				cnt++;
			}
			ans = max (ans, f (lef, rig));
		}
		return ans;
	}
};
