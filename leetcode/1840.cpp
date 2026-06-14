class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.emplace_back(vector <int> {1, 0});
        sort(restrictions.begin(), restrictions.end());
        for (int i = 1; i < restrictions.size(); i++) {
            restrictions[i - 1][1] = min(restrictions[i][1] + restrictions[i][0] - restrictions[i - 1][0], restrictions[i - 1][1]);
            restrictions[i][1] = min(restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0], restrictions[i][1]);
        }
        for (int i = restrictions.size() - 1; i > 0; i--) {
            restrictions[i - 1][1] = min(restrictions[i][1] + restrictions[i][0] - restrictions[i - 1][0], restrictions[i - 1][1]);
            restrictions[i][1] = min(restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0], restrictions[i][1]);
        }
        int ans = (*restrictions.rbegin())[1] + n - (*restrictions.rbegin())[0];
        for (int i = 1; i < restrictions.size(); i++) {
            ans = max ((restrictions[i - 1][1] + restrictions[i][1] - restrictions[i - 1][0] + restrictions[i][0]) / 2, ans);
        }
        return ans;
    }
};