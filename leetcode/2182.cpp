class Solution {
public:
	string repeatLimitedString (string s, int repeatLimit) {
		vector<int>cnt (26);
		for (char c : s)
			cnt[c - 'a']++;
		s.clear();
		int x = 0;
		while (true) {
			int F = 1e9, i;
			for (i = 25; ~i; i--) {
				if (s.empty() == 0 and s.back() == i + 'a' and cnt[i]) {
					F = 1;
					continue;
				}
				if (cnt[i])
					break;
			}
			if (!~i)
				break;
			s += string (min ({repeatLimit, cnt[i], F}), (char) (i + 'a'));
			cnt[i] -= min ({repeatLimit, cnt[i], F});
		}
		return s;
	}
};
