class Solution {
public:
    int clumsy(int n) {
        int ans = 0;
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (n == 3) {
            return 6;
        }
        for (int i = n - 3; i > 0; i -= 4)
            ans += i;
        for (int i = n; i - 2 > 0; i -= 4) {
            ans -= ((i * (i - 1)) / (i - 2));
            cout << (((i * (i - 1)) / (i - 2))) << " ";
        }
        if ((n % 4) == 2) {
            ans -= 2;
        }
        if ((n % 4) == 1) {
            ans --;
        }
        return ans + 2 * ((n * (n - 1)) / (n - 2));
    }
};