class Solution {
public:
	long long smallestNumber (long long num) {
		string s = to_string (num);
		int cntZeros = count (s.begin(), s.end(), '0');
		if (num >= 0) {
			sort (s.begin(), s.end());
			num = stoll (s);
			s = to_string (num);
			string zeros (cntZeros, '0');
			s.insert (1, zeros);
		}
		else {
			s = s.substr (1);
			sort (s.rbegin(), s.rend());
			s = "-" + s;
		}
		return stoll (s);
	}
};
