class Solution {
public:
	int canBeTypedWords(string text, string brokenLetters) {
		string s; istringstream inp(text); int cnt = 0;
		while (getline(inp, s, ' ' )) {
			for (auto &j : s) {
				if (count(brokenLetters.begin(), brokenLetters.end(), j))
					goto F;
			}
			cnt++;
F:;
		}
		return cnt;
	}
};