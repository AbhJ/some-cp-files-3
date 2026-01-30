class Solution {
public:
	vector<vector <int>> st, ul;
	int ans = 0;
	void dfs (int u, int p = - 1) {
		for (auto v : st[u]) if (v != p) {
				dfs (v, u);
			}
		for (auto v : ul[u]) if (v != p) {
				ans++;
				dfs (v, u);
			}
	}
	int minReorder (int n, vector<vector<int>>& connections) {
		st.resize (n + 1), ul.resize (n + 1);
		for (auto i : connections) {
			ul[i[0]].emplace_back (i[1]);
			st[i[1]].emplace_back (i[0]);
		}
		dfs (0);
		return ans;
	}
};