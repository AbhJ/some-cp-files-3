class Solution {
public:
    int func(int n){
        int cnt = 0;
        for(int i = 2; i * i <= n; i++){
            while((n % i) == 0){
                n /= i;
                cnt += i;
            }
        }
        if(cnt == 0)
            return n;
        return cnt + (n != 1 ? n : 0);
    }
    int smallestValue(int n) {
        int last = n + 1;
        while(n < last){
            last = n;
            n = func(last);
        }
        return last;
    }
};