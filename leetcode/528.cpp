// codeforces likes this
#include <time.h>
mt19937 rng (time (NULL));

class Solution {
public:
    vector<pair<int, int>> v;
    int W;
    Solution (vector<int>& w) {
        W = 0;
        v.clear();
        for (int i = 0; i < w.size(); i++) {
            W += w[i];
            v.emplace_back (W, i);
        }
    }

    int pickIndex() {
        int pos = uniform_int_distribution<int> (0, W) (rng);
        pair <int, int> p {pos, 0};
        return lower_bound (v.begin(), v.end(), p) -> second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */