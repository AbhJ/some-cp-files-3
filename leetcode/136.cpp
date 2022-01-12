class Solution {
public:
    int singleNumber(vector<int>& A) {
        int x = 0, n = A.size();
        for(int i = 0; i < n; i++){
            x ^= A[i];
        }
        return x; 
    }
};
