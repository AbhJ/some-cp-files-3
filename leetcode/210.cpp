class Solution {
public:
	vector<int> ord;
	vector<bool> vis;

	void toposort (int cur, vector<vector<int>> &adj) {
		vis[cur] = true;
		for (auto i : adj[cur]) {
			if (vis[i])
				continue;
			toposort (i, adj);
		}
		ord.emplace_back (cur);
	}

	vector<int> findOrder (int n, vector<vector<int>>& edges) {
		vector<vector<int>> adj (n);
		for (auto &x : edges) {
			adj[x[1]].emplace_back (x[0]);
		}
		vis = vector <bool> (n);
		ord.clear();
		for (int i = 0; i < n; i++) {
			if (!vis[i])
				toposort (i, adj);
		}
		reverse (ord.begin(), ord.end());
		// verify order of toposort
		map <int, int> posi;
		for (int i = 0; i < ord.size(); i++) {
			posi[ord[i]] = i;
		}
		for (auto &x : edges) {
			if (posi.count (x[0]) == 0 or posi.count (x[1]) == 0 or posi[x[0]] < posi[x[1]])
				return vector<int>();
		}
		for (int i = 0; i < n; i++) {
			if (posi.count (i) == 0)
				ord.emplace_back (i);
		}
		return ord;
	}
};