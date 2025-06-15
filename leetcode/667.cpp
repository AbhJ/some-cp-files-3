class Solution {
public:
	vector<int> constructArray (int n, int k) {
		int st = 1, la = n;
		vector <int> ret;
		while (n--) {
			if (k-- > 1 and (k & 1)) {
				ret.emplace_back (st++);
			}
			else
				ret.emplace_back (la--);
		}
		return ret;
	}
};