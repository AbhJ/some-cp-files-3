class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        deque <int> dec;
        multiset <pair <int, int>> foundGreater;
        vector <int> ans (n, - 1);
        for (int i = 0; i < n; i++) {
            while (foundGreater.empty() == 0 and foundGreater.begin() -> first < nums[i]) {
                ans [foundGreater.begin() -> second] = nums[i];
                foundGreater.erase(foundGreater.begin());
            }
            while (dec.empty() == 0 and nums[dec.back()] < nums[i]) {
                foundGreater.emplace(nums[dec.back()], dec.back());
                dec.pop_back();
            }
            dec.push_back(i);
        }
        return ans;
    }
};