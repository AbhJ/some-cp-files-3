class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector <vector <pair <int, int>>> a (n);
        for (auto v: edges) {
            a[v[0]].emplace_back(v[1], v[2]);
            a[v[1]].emplace_back(v[0], v[2]);
        }
        // moves left while reaching a bignode should be as max as possible
        // if theres an edge between a and b and x number of nodes left
        // to see after visiting x and y number of nodes left after visiting
        // b, min (edge_size, x + y) nodes of this edge shall be covered
        priority_queue <pair<int, int>> q;
        vector <int> nodesSeen (n, - 1);
        q.emplace(maxMoves, 0);
        while (q.empty() == 0) {
            auto [moves, u] = q.top();
            q.pop();
            if (~nodesSeen[u])
                continue;
            nodesSeen[u] = moves;
            for (auto [j, cost]: a[u]) {
                if (~nodesSeen[j])
                    continue;
                if (moves - cost - 1 < 0)
                    continue;
                q.emplace(moves - cost - 1, j);
            }
        }
        int ans = 0;
        for (auto i: nodesSeen) {
            if (~i)
                ans++;
        }
        for (auto v: edges) {
            int lef = v[0], rig = v[1];
            int lefCnt = (~nodesSeen[lef] ? nodesSeen[lef] : 0),
                rigCnt = (~nodesSeen[rig] ? nodesSeen[rig] : 0);
            // cout << lef << " " << lefCnt << "\n" << rig << " " << rigCnt << "\n";
            ans += min (v[2], lefCnt + rigCnt);
        }
        return ans;
    }
};