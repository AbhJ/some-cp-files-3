class Solution {
public:
    int ok(vector<int>& a, int mm, int m, int k){
        int cons = 0, cnt = 0, ok = 0;
        for(auto i: a){
            if(i <= mm and (cons == 0 or ok == 1))
                cons++;
            else
                cons = 0;
            if(cons == k)
                cnt++, cons = 0;
            ok = i <= mm;
        }
        return cnt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, r = (int)1e9 + 1, mm;
        while(l < r){
            mm = l + r >> 1;
            if(ok(bloomDay, mm, m, k))
                r = mm;
            else
                l = mm + 1;
        }
        if(r == (int)1e9 + 1)
            return - 1;
        return r;
    }
};
