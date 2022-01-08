class Solution {
public:
	int dx[3] = {- 1, 0, 1};
	int func (int lev, int lef, int rig, int &n, int &m, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid) {
		if (lev == n)
			return 0;
		if (lef == - 1 or lef == m or rig == - 1 or rig == m)
			return - 1e9;
		if (~dp[lev][lef][rig])
			return dp[lev][lef][rig];
		int &ans = dp[lev][lef][rig];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				ans = max (ans, grid[lev][lef] + (lef != rig ? grid[lev][rig] : 0) + func (lev + 1, lef + dx[i], rig + dx[j], n, m, dp, grid));
		return ans;
	}
	int cherryPickup (vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		if (n == 0)
			return 0;
		if (m == 0)
			return 0;
		vector<vector<vector<int>>>dp (n, vector<vector<int>> (m, vector<int> (m, - 1)));
		return func (0, 0, m - 1, n, m, dp, grid);
	}
};

