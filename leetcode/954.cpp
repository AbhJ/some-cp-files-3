class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        multiset <int> s;
        for (int i = 0; i < n; i++) {
            s.emplace(arr[i]); 
        }
        while (s.empty() == 0) {
            int x = *s.begin();
            s.erase(s.begin());
            if (((x < 0) and (s.contains(x / 2) == 0 and (x & 1 ^ 1))) or ((x >= 0) and (s.contains(x * 2) == 0)))
                return false;
            if (x < 0 and s.contains(x / 2) != 0 and (x & 1 ^ 1)) {
                s.erase (s.find(x / 2));
                continue;
            }
            if (x >= 0 and s.contains(x * 2) != 0) {
                s.erase (s.find(x * 2));
                continue;
            }
            if (s.contains(x / 2) != 0 and (x & 1 ^ 1)) {
                s.erase (s.find(x / 2));
                continue;
            }
            if (s.contains(x * 2) != 0) {
                s.erase (s.find(x * 2));
                continue;
            }
            return false;
        }
        return true;
    }
};