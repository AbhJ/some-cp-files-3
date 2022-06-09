class Solution {
public:
    int b_search(vector<int> &a, int b, int l, int r, int m = - 1){
        if(l > r)
            return - 1;
//         standard sorted binary search
        int L = l, R = r;
        while(l < r){
            m = (l + r) / 2;
            if(a[m] >= b)
                r = m;
            else
                l = m + 1;
        }
        if(r <= R and r >= L and a[r] == b)
            return r;
        return - 1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n - 1, m, M;
        while(l < r){
            m = (l + r + 1) / 2;
            if(nums[m] >= nums[r])
                l = m;
            else
                r = m - 1;
        }
        M = l;
        while(M - 1 != - 1 and nums[M - 1] > nums[M])
            M --;
        while(M + 1 != n and nums[M + 1] > nums[M])
            M ++;
        int left_pos = b_search(nums, target, M + 1, n - 1);
        int right_pos = b_search(nums, target, 0, M);
        if(~left_pos){
            return left_pos;
        }
        return right_pos;
    }
};
