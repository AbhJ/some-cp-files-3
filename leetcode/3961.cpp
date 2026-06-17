class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        // if any of them is size 1, we cannot have second smallest
        // choose one vectors smallest, and all others second smallest
        long long mi, semi, _mi = 1e9, _semi = 1e9, ans = 0, semiSum = 0;
        for (auto &v: units) {
            mi = *min_element(v.begin(), v.end());
            semi = 1e9;
            bool miSeen = false;
            for (auto &unit: v) {
                if (unit == mi) {
                    if (miSeen)
                        semi = mi;
                    else
                        miSeen = true;
                }
                else {
                    semi = min ((long long) unit, semi);
                }
            }
            ans += mi;
            if (semi != 1e9)
                semiSum += semi;
            if (_mi > mi) 
                _mi = mi;
            if (semi != 1e9 and _semi > semi)
                _semi = semi;
        }
        return max (semiSum - _semi + _mi, ans);
    }
};