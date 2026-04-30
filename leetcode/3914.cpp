class Solution {
public:
    long long minOperations(vector<int>& a) {
        int n = a.size();
        long long ans = 0;
        for (int i = n - 2; ~i; i--) {
            if (a[i] > a[i + 1])
                ans += a[i] - a[i + 1];
        }
        return ans;
    }
};