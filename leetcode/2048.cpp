class Solution {
public:
	int nextBeautifulNumber (int n) {
		for (int i = n + 1; i < 3e6; i++) {
			string s = to_string (i);
			vector<int>v (10);
			for (char j : s)
				v[j - '0']++;
			int F = 0;
			for (int ii = 0; ii < 10; ii++) {
				if (v[ii] != ii and v[ii] != 0)
					F = 1;
			}
			if (F == 0)
				return i;
		}
		return - 1;
	}
};
