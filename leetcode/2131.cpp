class Solution {
public:
	int longestPalindrome (vector<string> &words) {
		map<string, int> f;
		for (string word : words)
			f[word]++;
		int answer = 0, hasCenterWord = 0;
		for (auto [word, freq] : f) {
			string revWord = word;
			reverse (revWord.begin(), revWord.end());
			if (word == revWord) {
				answer += ((freq >> 1) << 1);
				if (freq & 1)
					hasCenterWord = 1;
			}
			else {
				int revFreq = f[revWord];
				answer += (min (freq, revFreq) << 1);
				f.erase (revWord);
			}
		}
		return ((answer + hasCenterWord) << 1);
	}
};
