class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map <char, vector<int>> pos;
        int ans = key.size();
        for (int i = 0; i < ring.size(); i++) {
            pos[ring[i]].emplace_back(i);
        }
        priority_queue <tuple <int, int, int>, vector <tuple <int, int, int>>, greater <tuple <int, int, int>>>  q; // cost, index of key covered, position of ring clicked
        q.emplace (tuple <int, int, int> {0, 0, 0});
        vector<vector<bool>> vis (key.size() + 1, vector<bool> (ring.size() + 1));
        while (!q.empty()) {
            auto [cos, ind, las] = q.top();
            q.pop();
            if (vis[ind][las]) {
                continue;
            }
            vis[ind][las] = true;
            if (ind == key.size()) {
                return cos + ind;
            }
            for (auto cur: pos[key[ind]]) {
                q.emplace (tuple <int, int, int> {cos + min (abs(cur - las), (int) ring.size() - abs(cur - las)), ind + 1, cur});
            }
        }
        return - 1;
    }
};