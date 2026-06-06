class Solution {
public:
	vector<int> missingRolls (vector<int>& rolls, int mean, int n) {
		int m = rolls.size(), tot = accumulate (rolls.begin(), rolls.end(), 0);
		tot = mean * (n + m) - tot;
		vector <int> ans (n);
		for (int i = 0; i < n; i++) {
			for (int v = 1; v <= 6; v++) {
				if ((tot - v) >= (n - i - 1) and (tot - v) <= 6 * (n - i - 1)) {
					tot -= v;
					ans[i] = v;
					break;
				}
			}
			if (!ans[i])
				return vector <int> {};
		}
		return ans;
	}
};