class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size(); long long ans = 0;
        vector<map<long long, long long>>m(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                m[i][(long long)a[i] - (long long)a[j]] += m[j][(long long)a[i] - (long long)a[j]] + 1;
                ans += m[j][(long long)a[i] - (long long)a[j]];
            }
        }
        return ans;
    }
};
