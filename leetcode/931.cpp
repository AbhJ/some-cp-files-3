class Solution {
public:
	int minFallingPathSum (vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size(), ans = 1e9;
		for (int r = 1; r < n; r++) {
			for (int c = 0; c < m; c++) {
				int mid = matrix[r - 1][c];
				int left = (c > 0) ? matrix[r - 1][c - 1] : 1e9;
				int right = (c < m - 1) ? matrix[r - 1][c + 1] : 1e9;
				matrix[r][c] += min ({left, mid, right});
			}
		}
		for (int c = 0; c < m; c++)
			ans = min (ans, matrix[n - 1][c]);
		return ans;
	}
};