class Solution {
public:
	set<string> words;
	string sent;
	vector<string> sentences;
	int n;

	void func (int i, string cur) {
		if (i == n) {
			sentences.emplace_back (cur);
			return;
		}
		for (int j = 1; j <= n - i; j++) {
			string attemptedWord = sent.substr (i, j);
			// i + j - 1
			if (words.count (attemptedWord) == 0)
				continue;
			if (cur.empty())
				func (i + j, attemptedWord);
			else
				func (i + j, cur + " " + attemptedWord);
		}
	}

	vector<string> wordBreak (string A, vector<string> &B) {
		sent = A;
		words.clear();
		sentences.clear();
		for (string word : B)
			words.emplace (word);
		n = sent.length();
		string cur;
		func (0, cur);
		return sentences;
	}
};
