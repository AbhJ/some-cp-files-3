class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> V;
        sort(intervals.begin(), intervals.end());
        int start, end = - 1;
        for(auto v: intervals){
            if(v[0] > end){
                if(~end){
                    V.emplace_back(vector<int>{start, end});
                }
                start = v[0];
                end = v[1];
            }
            else 
            end = max(end, v[1]);
        }
        if(~end){
            V.emplace_back(vector<int>{start, end});
        }
        return V;
    }
};