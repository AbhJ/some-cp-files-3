class Solution {
public:
	int maximalRectangle (vector<vector<char>> &a) {
		int n = a.size(), m = a[0].size(), ans = 0;
		vector<vector<int>>hist (n, vector<int> (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j == 0)
					hist[i][j] = a[i][j] == '1';
				else
					hist[i][j] = ((a[i][j] == '1') ? 1 + hist[i][j - 1] : 0);
			}
		}
		for (int j = 0; j < m; j++) {
			stack<int> s;
			vector<int> l (n, - 1), r (n, n);
			for (int i = 0; i < n; i++) {
				while (s.empty() == 0 and hist[s.top()][j] >= hist[i][j])
					s.pop();
				if (s.empty() == 0)
					l[i] = s.top();
				s.emplace (i);
			}
			s = stack<int> ();
			for (int i = n - 1; ~i; i--) {
				while (s.empty() == 0 and hist[s.top()][j] >= hist[i][j])
					s.pop();
				if (s.empty() == 0)
					r[i] = s.top();
				s.emplace (i);
			}
			for (int i = 0; i < n; i++)
				ans = max (ans, (r[i] - l[i] - 1) * hist[i][j]);
		}
		return ans;
	}
};
