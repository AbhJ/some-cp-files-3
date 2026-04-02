class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        reverse (energy.begin(), energy.end());
        int n = energy.size(), ans = - 1e9;
        vector <int> a (k);
        for (int i = 0; i < n; i++) {
            a [i % k] += energy[i];
            ans = max (a[i % k], ans);
        }
        return ans;
    }
};