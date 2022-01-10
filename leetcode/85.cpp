class Solution {
public:
	int maximalRectangle (vector<vector<char>> &A) {
		int n = A.size(), m = A[0].size(), answer = 0;
		vector <int> lowestZeroInCol (m, -1);
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (A[i][j] == '0')
					lowestZeroInCol[j] = i;
			}
			stack<int>s;
			vector<int> l (m, -1), r (m, m);
			for (int j = 0; j < m; j ++) {
				while (s.empty() == 0 and lowestZeroInCol[s.top()] <= lowestZeroInCol[j])
					s.pop();
				if (s.empty() == 0)
					l[j] = s.top();
				s.push (j);
			}
			s = stack<int>();
			for (int j = m - 1; j > - 1; j --) {
				while (s.empty() == 0 and lowestZeroInCol[s.top()] <= lowestZeroInCol[j])
					s.pop();
				if (s.empty() == 0)
					r[j] = s.top();
				s.push (j);
			}
			for (int j = 0; j < m; j ++)
				answer = max (answer, (r[j] - l[j] - 1) * (i - lowestZeroInCol[j]));
		}
		return answer;
	}
};

