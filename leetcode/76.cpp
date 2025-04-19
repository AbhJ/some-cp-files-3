class Solution {
public:
	string minWindow (string s, string t) {
		int n = s.length(), m = t.length(), l = 0, r = - 1;
		map <char, int> mapLeft;
		for (char c : t)
			mapLeft [c]++;
		int st = - 1, en = 1e9, cntLeft = m;
		while (r < n - 1) {
			if (mapLeft[s[++r]]-- > 0)
				cntLeft--;
			// if this s[r] is not in t, mapLeft[s[++r]] will become negative
			// as long as s[r] is present in the window
			while (cntLeft == 0) {
				if (r - l < en - st)
					en = r, st = l;
				// try to shorten the window
				if (mapLeft[s[l]]++ >= 0)
					cntLeft++;
				// if s[l] is in t more times than in the sliding window
				// mapLeft[s[l]] will become non negative
				l++;
			}
		}
		if (en == 1e9)
			return "";
		return s.substr (st, en - st + 1);
	}
};