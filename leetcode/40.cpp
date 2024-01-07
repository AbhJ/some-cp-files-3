class Solution {
public:
    void f(int start, vector<int> &chosen, vector<vector<int>> &ans, vector<int>& a, int target){
        int n = a.size();
        if (target == 0)
            ans.emplace_back(chosen);
        if (start == n)
            return;
        for (int i = start; i < n; i++){
            if(i != start and i != 0 and a[i] == a[i - 1])
                continue;
            if (target - a[i] < 0)
                break;
            chosen.emplace_back(a[i]);
            f(i + 1, chosen, ans, a, target - a[i]);
            chosen.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        vector<int> chosen;
        vector<vector<int>> ans;
        f(0, chosen, ans, a, target);
        return ans;
    }
};