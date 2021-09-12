class Solution {
public:
	int ok(int x, int y, int n, int m) {
		return x >= 0 and y >= 0 and x < n and y < m;
	}
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int x = entrance[0], y = entrance[1];
		priority_queue<tuple<int, int, int>>q;
		vector<int>dx{0, - 1, 1, 0}, dy{1, 0, 0, - 1};
		q.emplace(0, x, y);
		vector<vector<int>>dp(maze.size(), vector<int>(maze[0].size(), 1e9));
		assert(ok(x, y, maze.size(), maze[0].size()) and maze[x][y] == '.');
		dp[x][y] = 0;
		int finalCost = 1e9;
		while (q.empty() == 0) {
			auto [cost, x, y] = q.top();
			q.pop();
			cost = - cost;
			if ((x == 0 or x == maze.size() - 1 or y == 0 or y == maze[0].size() - 1) and (x != entrance[0] or y != entrance[1]))
				finalCost = min(cost, finalCost);
			if (cost > dp[x][y])
//                 already been updated
				continue;
			assert(cost == dp[x][y]);
			for (int k = 0; k < 4; k++) {
				int X = x + dx[k], Y = y + dy[k];
				if (ok(X, Y, maze.size(), maze[0].size()) and cost + 1 < dp[X][Y] and maze[X][Y] == '.')
					dp[X][Y] = cost + 1, q.emplace(- dp[X][Y], X, Y);
			}
		}
		return finalCost == 1e9 ? - 1 : finalCost;
	}
};