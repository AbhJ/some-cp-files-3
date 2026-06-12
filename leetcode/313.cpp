class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue <tuple <long long, int, int>> q;
        for (auto p: primes)
            q.emplace (- p, p, 1);
        int cur = 1;
        vector <long long> uglies (n);
        uglies [0] = 1;
        while (cur < n) {
            auto [ugly, p, pos] = q.top();
            ugly = - ugly;
            q.pop();
            if (uglies[cur - 1] < ugly) {
                uglies[cur++] = ugly;
            }
            q.emplace (- uglies[pos] * p, p, pos + 1);
        }
        return uglies.back();
    }
};