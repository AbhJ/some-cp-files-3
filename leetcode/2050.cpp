class Solution {
public:
	int minimumTime (int n, vector<vector<int>>& relations, vector<int>& time) {
		vector <vector <int>> a (n + 1);
		vector <int> inDeg (n + 1);
		queue <int> q;
		vector <int> ans (n + 1);
		int ret = 0;
		for (auto v : relations) {
			a[v[0]].emplace_back (v[1]);
			inDeg[v[1]]++;
		}
		for (int i = 1; i <= n; i++) {
			ans [i] = time [i - 1];
			if (inDeg[i])
				continue;
			q.emplace (i);
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : a[u]) {
				ans[v] = max (ans[u] + time [v - 1], ans[v]);
				if (--inDeg [v] == 0)
					q.emplace (v);
			}
		}
		return *max_element (ans.begin(), ans.end());
	}
};