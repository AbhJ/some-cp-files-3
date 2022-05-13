class Solution {
public:
	vector<string>v;
	void f (string &s, int open, int &n) {
		int len = s.length();
		int close = len - open;
		if (close > open)
			return;
		if (len == 2 * n) {
			if (open == n)
				v.emplace_back (s);
			return;
		}
		s += "(";
		f (s, open + 1, n);
		s.pop_back();
		s += ")";
		f (s, open, n);
		s.pop_back();
	}

	vector<string> generateParenthesis (int n) {
		v.clear();
		string s;
		f (s, 0, n);
		return v;
	}
};
