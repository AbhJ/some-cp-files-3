class Solution {
public:
	vector<int> gardenNoAdj (int n, vector<vector<int>>& paths) {
		queue <int> q;
		for (int i = 1; i <= n; i++)
			q.emplace (i);
		vector <vector<int>> a (n + 1);
		vector <int> col (n);
		for (auto v : paths) {
			a[v[0]].emplace_back (v[1]);
			a[v[1]].emplace_back (v[0]);
		}
		while (q.empty() == 0) {
			int x = q.front();
			q.pop();
			if (col[x - 1])
				continue;
			vector <bool> available (5, true);
			for (int u : a[x]) {
				q.emplace (u);
				available[col[u - 1]] = false;
			}
			for (int curCol = 1; curCol < 5; curCol++) if (available[curCol]) {
					col[x - 1] = curCol;
					break;
				}
		}
		return col;
	}
};