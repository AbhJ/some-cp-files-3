class Solution {
public:
	int minimumSum (int num) {
		int ans = 1e9;
		string s = to_string (num);
		while (s.size() != 4)
			s = "0" + s;
		for (int i = 1; i < (1 << 4) - 1; i++) {
			string a, b;
			for (int j = 0; j < 4; j++) {
				if ((i >> j) & 1)
					a += s[j];
				else
					b += s[j];
			}
			sort (a.begin(), a.end());
			sort (b.begin(), b.end());
			ans = min (ans, stoi (a) + stoi (b));
		}
		return ans;
	}
};
