class Solution {
public:
	vector<vector<int>> paths;
	int n;
	void dfs (int u, vector<int>& cur, vector<bool>& vis,
	          vector<vector<int>>& graph) {
		if (u == n - 1) {
			paths.emplace_back (cur);
			return;
		}
		for (int v : graph[u]) {
			if (vis[v])
				continue;
			vis[v] = true;
			cur.emplace_back (v);
			dfs (v, cur, vis, graph);
			vis[v] = false;
			cur.pop_back();
		}
	}
	vector<vector<int>> allPathsSourceTarget (vector<vector<int>>& graph) {
		n = graph.size();
		vector <int> cur {0};
		vector <bool> vis (n);
		vis[0] = true;
		paths.clear();
		dfs (0, cur, vis, graph);
		return paths;
	}
};