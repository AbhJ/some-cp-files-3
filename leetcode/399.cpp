class Solution {
public:
	// m maps the strings to nodes
	map <string, int> m;
	vector<vector<pair<int, double>>> adj;
	vector<vector<double>>ans;
	int n;
	void dfs (int u, int tar, int src, vector<bool>& vis, double cur = 1) {
		ans [src][u] = cur;
		if (u == tar) {
			return;
		}
		if (ans[src][tar] != - 1)
			return;
		if (vis[u])
			return;
		vis[u] = true;
		for (auto [x, y] : adj[u]) {
			dfs (x, tar, src, vis, cur * y);
		}
	}
	vector<double> calcEquation (vector<vector<string>>& equations,
	                             vector<double>& values, vector<vector<string>>& queries) {
		n = 0;
		m.clear();
		for (int i = 0; i < equations.size(); i++) {
			if (m.count (equations[i][0]) == 0)
				m[equations[i][0]] = n++;
			if (m.count (equations[i][1]) == 0)
				m[equations[i][1]] = n++;
			adj.resize (n);
			adj[m[equations[i][0]]].emplace_back (m[equations[i][1]], values[i]);
			adj[m[equations[i][1]]].emplace_back (m[equations[i][0]], 1 / values[i]);
		}
		ans.resize (n, vector<double> (n, - 1));
		vector <double> ret;
		for (auto q : queries) {
			if (m.count (q[0]) == 0 or m.count (q[1]) == 0) {
				ret.emplace_back (- 1);
				continue;
			}
			vector<bool> vis (n);
			dfs (m[q[0]], m[q[1]], m[q[0]], vis);
			ret.emplace_back (ans[m[q[0]]][m[q[1]]]);
		}
		return ret;
	}
};