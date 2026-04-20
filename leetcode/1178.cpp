class Solution {
public:
	vector<int> findNumOfValidWords (vector<string>& words,
	                                 vector<string>& puzzles) {
		map <int, int> m;
		vector <int> v;
		for (auto s : words) {
			int ma = 0;
			for (auto i : s) {
				ma |= (1 << (i - 'a'));
			}
			m[ma]++;
		}
		for (auto s : puzzles) {
			int ma = 0, ans = 0;
			for (auto i : s) {
				ma |= (1 << (i - 'a'));
			}
			for (int su = ma; su > 0; su = (su - 1) & ma) {
				// Process submask s
				if ((su & (1 << (s[0] - 'a'))) == 0)
					continue;
				ans += m[su];
			}
			v.emplace_back (ans);
		}
		return v;
	}
};