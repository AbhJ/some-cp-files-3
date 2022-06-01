class Solution {
public:
	int percentageLetter (string s, char letter) {
		double ans = 0;
		for (char c : s)
			ans += (c == letter);
		return ((ans * 100) / (int)s.length());
	}
};
