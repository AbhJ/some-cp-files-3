class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        priority_queue <pair <int, int>> q; // end time, value
        sort (events.begin(), events.end());
        int max_first = 0, max_ans = 0;
        for (auto &v: events) {
            while ((q.empty() == 0) and ((- q.top().first) < v[0])) {
                max_first = max (q.top().second, max_first);
                q.pop();
            }
            max_ans = max (max_first + v[2], max_ans);
            q.emplace(- v[1], v[2]);
        }
        return max_ans;
    }
};