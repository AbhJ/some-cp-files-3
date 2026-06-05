class Solution {
public:
	int maxPointsInsideSquare (vector<vector<int>>& points, string s) {
		vector <int> x (26, 1e9 + 1);
		int sec_mi = 1e9 + 1, ans = 0;
		for (int i = 0; i < points.size(); i++) {
			if (max (abs (points[i][0]), abs (points[i][1])) < x[s[i] - 'a']) {
				sec_mi = min (x[s[i] - 'a'], sec_mi);
				x[s[i] - 'a'] = max (abs (points[i][0]), abs (points[i][1]));
			}
			else {
				sec_mi = min (max (abs (points[i][0]), abs (points[i][1])), sec_mi);
			}
		}
		for (int i = 0; i < 26; i++) {
			if (x[i] < sec_mi)
				ans++;
		}
		return ans;
	}
};