class Solution {
public:
	int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
		int n = passingFees.size(), m = edges.size();
		vector<vector<pair<int, int>>>adj(n);
		vector<int>somoy(n, 1e9), taka(n, 1e9);
		for (int i = 0; i < edges.size(); i++) {
			int x = edges[i][0];
			int y = edges[i][1];
			int tim = edges[i][2];
			adj[x].emplace_back(y, tim);
			adj[y].emplace_back(x, tim);
		}
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>q;
		q.emplace(passingFees[0], 0, 0);
		somoy[0] = taka[0] = 0;
		while (q.empty() == 0) {
			auto [cost, time, x] = q.top();
			q.pop();
			for (auto [i, exTime] : adj[x]) {
				int totTime = exTime + time;
				int totCost = passingFees[i] + cost;
				if (totTime > maxTime)
					continue;
				if (totCost < taka[i])
					taka[i] = totCost, somoy[i] = totTime, q.emplace(taka[i], somoy[i], i);
//                 better time at a worst cost may be problematic later as we want to minimise cost if time fits the boundaries, so
//                 we do not store it in dp at the moment. Only when the cost is optimal for some successor shall we store it.
				else if (totTime < somoy[i])
					somoy[i] = totTime, q.emplace(totCost, somoy[i], i);
			}
		}
		if (somoy[n - 1] > maxTime)
			return - 1;
		return taka[n - 1];
	}
};