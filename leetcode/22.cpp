class Solution {
public:
	int len;

	void generator (vector<string> &v, int open, string &cur) {
		if (open > len or open < 0)
			return;
		if (cur.length() == (len << 1)) {
			if (open == 0 and (v.empty() or v.back() != cur))
				v.emplace_back (cur);
			return;
		}
		cur += '(';
		generator (v, open + 1, cur);
		cur.pop_back();
		cur += ')';
		generator (v, open - 1, cur);
		cur.pop_back();
	}

	vector<string> generateParenthesis (int n) {
		vector<string> v;
		string s;
		len = n;
		generator (v, 0, s);
		return v;
	}
};
