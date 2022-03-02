class Solution {
public:
	int minimumTime (string s) {
		int ans = 1e9, cosLef = 0, pos = - 1;
		for (char c : s) {
			pos++;
			if (c != '0')
				cosLef = min (cosLef + 2, pos + 1);
			ans = min (ans, cosLef + (int)s.length() - pos - 1);
		}
		return ans;
	}
};
