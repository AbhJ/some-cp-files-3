class Solution {
public:
	int countPalindromicSubsequence (string s) {
		vector<int> f (26, - 1), l (26, - 1);
		vector<bool> o (26);
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			l[s[i] - 'a'] = i;
			if (~f[s[i] - 'a'])
				continue;
			f[s[i] - 'a'] = i;
		}
		for (int c = 0; c < 26; c++)
			if (~f[c] and ~l[c]) {
				for (int i = f[c] + 1; i < l[c]; i++)
					o[s[i] - 'a'] = 1;
				ans += accumulate (o.begin(), o.end(), 0);
				if (c + 1 != 26)
					fill (o.begin(), o.end(), 0);
			}
		return ans;
	}
};
