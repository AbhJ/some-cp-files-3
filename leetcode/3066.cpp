class Solution {
public:
    int minOperations (vector<int>& nums, int k) {
        priority_queue <long long, vector<long long>, greater<long long>> q;
        int steps = 0;
        for (int i : nums)
            q.emplace (i);
        while (q.empty() == 0) {
            if (q.top() >= k)
                return steps;
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
            q.emplace (x + min (x, y) + y);
            steps++;
        }
        return steps;
    }
};