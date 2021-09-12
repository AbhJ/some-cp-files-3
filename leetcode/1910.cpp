class Solution {
public:
	string removeOccurrences(string s, string part) {
		string S = s;
		while (S.find(part) != string::npos) {
			S.clear();
			int F = 0;
			for (int i = 0; i < (int)s.length(); i++) {
				if (s.substr(i, (int)part.length()) == part and F == 0) {
					i += (int)part.length() - 1;
					F = 1;
				}
				else {
					S += s[i];
				}
			}
			s = S;
		}
		return S;
	}
};