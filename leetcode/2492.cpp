class Solution {
public:
	
	const int INF = 1000000000;
	vector<vector<pair<int, int>>> adj;

	void dijkstra(int s, vector<int> & d, vector<int> & p) {
		int n = adj.size();
		d.assign(n, INF);
		p.assign(n, -1);
		set<pair<int, int>> q;
		q.insert({INF, s});
		while (!q.empty()) {
			int v = q.begin()->second;
			q.erase(q.begin());

			for (auto edge : adj[v]) {
				int to = edge.first;
				int len = edge.second;

				if (min(d[v], len) < d[to]) {
					q.erase({d[to], to});
					d[to] = min(d[v], len);
					p[to] = v;
					q.insert({d[to], to});
				}
			}
		}
	}
	
	int minScore(int n, vector<vector<int>>& roads) {
		adj = vector<vector<pair<int, int>>>(n);
		for(auto road: roads){
			adj[road[0] - 1].emplace_back(road[1] - 1, road[2]);
			adj[road[1] - 1].emplace_back(road[0] - 1, road[2]);
		}
		vector<int>d, p;
		dijkstra(0, d, p);
		return d[n - 1];
	}
};