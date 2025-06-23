class Solution {
public:
    int longestMountain (vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector <int> l (n), r (n, - 1);
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] >= arr[i])
                l[i] = i;
            else
                l[i] = l[i - 1];
            if (arr[i - 1] <= arr[i])
                r[i] = i;
            else {
                r[i] = r[i - 1];
                if (r[i] != - 1 and l[r[i]] != r[i]) {
                    ans = max (ans, i - l[r[i]] + 1);
                }
            }
        }
        return ans;
    }
};