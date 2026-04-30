class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) if (i != j) {
                int y_ma = min (topRight[i][1], topRight[j][1]), x_ma = min (topRight[i][0], topRight[j][0]);
                int y_mi = max (bottomLeft[i][1], bottomLeft[j][1]), x_mi = max (bottomLeft[i][0], bottomLeft[j][0]);
                if (y_ma > y_mi and x_ma > x_mi)
                    ans = max (1LL * min(x_ma - x_mi, y_ma - y_mi) * min(x_ma - x_mi, y_ma - y_mi), ans);
            }
        return ans;
    }
};