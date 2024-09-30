class Solution {
public:
	int maximalRectangle (vector<vector<char>>& matrix) {
		int n = matrix.size(), m = matrix[0].size(), ans = 0;
		vector<vector<int>> v (n + 1, vector<int> (m + 1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				v[i + 1][j + 1] = (matrix[i][j] == '1' ? 1 + v[i + 1][j] : 0);
			}
		}
		for (int j = 1; j <= m; j++) {
			vector <int> l (n + 1, 0), r (n + 1, n + 1);
			stack <int> s;
			for (int i = 1; i <= n; i++) {
				while (s.empty() == 0 and v[s.top()][j] >= v[i][j]) {
					s.pop();
				}
				if (s.empty() == 0)
					l[i] = s.top();
				s.emplace (i);
			}
			s = stack <int> ();
			for (int i = n; i >= 1; i--) {
				while (s.empty() == 0 and v[s.top()][j] >= v[i][j]) {
					s.pop();
				}
				if (s.empty() == 0)
					r[i] = s.top();
				s.emplace (i);
			}
			for (int i = 1; i <= n; i++) {
				ans = max ((r[i] - l[i] - 1) * v[i][j], ans);
			}
		}
		return ans;
	}
};