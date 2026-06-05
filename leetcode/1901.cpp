class Solution {
public:
	vector<int> findPeakGrid (vector<vector<int>>& mat) {
		int n = mat.size(), m = mat[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bool poss = true;
				for (auto d : vector <pair<int, int>> {{0, - 1}, {0, 1}, {1, 0}, {- 1, 0}}) {
					int X = i + d.first, Y = j + d.second;
					if (X > n - 1 or Y > m - 1 or X < 0 or Y < 0)
						continue;
					if (mat[X][Y] > mat[i][j])
						poss = false;
				}
				if (poss == true)
					return vector <int> {i, j};
			}
		}
		return vector <int> {- 1, - 1};
	}
};