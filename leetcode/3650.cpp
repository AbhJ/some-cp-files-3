class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector <vector<pair<int, int>>> a(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            a[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
            a[edges[i][1]].emplace_back(edges[i][0], edges[i][2] << 1);
        }
        vector <int> dp (n + 1, 1e9);
        priority_queue <pair<int, int>> q;
        q.emplace(0, 0);
        int ans = 0;
        dp[0] = 0;
        while (q.empty() == 0) {
            auto [W, u] = q.top();
            q.pop();
            for (auto [v, w]: a[u]) {
                if (dp[u] + w < dp[v])
                    q.emplace(- (dp[u] + w), v);
                dp[v] = min (dp[v], dp[u] + w);
            }
        }
        return dp[n - 1] == 1000000000 ? - 1 : dp[n - 1];
    }
};