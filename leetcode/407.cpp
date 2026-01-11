class Solution {
public:
	vector <int> dx {- 1, 0, 1, 0}, dy {0, - 1, 0, 1};
	int trapRainWater (vector<vector<int>>& heightMap) {
		int n = heightMap.size(), m = heightMap[0].size(), ans = 0;
		vector<vector<bool>> vis (n, vector <bool> (m));
		priority_queue <tuple<int, int, int>>q;
		// wall height, x, y
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
					q.push (tuple<int, int, int> {- heightMap[i][j], i, j});
					vis[i][j] = 1;
				}
			}
		while (q.empty() == 0) {
			auto [wallH, X, Y] = q.top();
			wallH = - wallH;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int x = X + dx[k], y = Y + dy[k];
				if (x < 0 or x > n - 1 or y < 0 or y > m - 1 or vis[x][y])
					continue;
				ans += max (0, wallH - heightMap[x][y]);
				int newH = max (heightMap[x][y], wallH);
				q.push (tuple<int, int, int> {- newH, x, y});
				vis[x][y] = 1;
			}
		}
		return ans;
	}
};