class Solution {
public:
	string pro (string word) {
		if (word.length() <= 2) {
			transform (word.begin(), word.end(), word.begin(), ::tolower);
			return word;
		}
		transform (word.begin() + 1, word.end(), word.begin() + 1, ::tolower);
		return string (1, toupper (word[0])) + word.substr (1);
	}
	string capitalizeTitle (string title) {
		string word = "", fin;
		for (auto x : title) {
			if (x == ' ') {
				fin += pro (word) + " ";
				word = "";
			}
			else
				word = word + x;
		}
		return fin + pro (word);
	}
};

