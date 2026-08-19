class Solution {
public:
	bool isPalindrome (string s) {
		string _s = s;
		reverse (s.begin(), s.end());
		return s == _s;
	}
	map <int, vector<vector<string>>> m;
	vector<vector<string>> dfs (string s, int ind, vector<string> &v) {
		vector<vector<string>> ans;
		if (ind == s.length())
			return vector<vector<string>> (1);
		if (m.contains (ind))
			return m[ind];
		for (int i = ind; i < s.length(); i++) {
			string _s = s.substr (ind, i - ind + 1);
			if (isPalindrome (_s)) {
				auto _v = dfs (s, i + 1, v);
				for (auto j : _v) {
					j.insert (j.begin(), _s);
					ans.emplace_back (j);
				}
			}
		}
		return m[ind] = ans;
	}
	vector<vector<string>> partition (string s) {
		vector<string> v;
		return dfs (s, 0, v);
	}
};