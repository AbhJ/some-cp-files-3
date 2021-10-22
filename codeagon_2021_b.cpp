int Solution::solve(int A, int B) {
    int ans = 0;
    if(A > B)
        swap(A, B);
    while(A and B){
        while(A != 0)
            A /= 2, ans++;
    }
    if(A == 0 and B == 0)
        return 0;
    if(B == 1)
        return ++ans;
    return ans + (B != 0) * 2;
}
