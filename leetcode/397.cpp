class Solution {
public:
	int integerReplacement (int N) {

        // 101
        // —
        // 100
        // 10
        // 1
        // ++

        // 110
        // 11
        // 10
        // 1
        
		long long n = N;
		int ans = 0;
		while (n != 1) {
			ans++;
			if (n & 1 ^ 1)
				n >>= 1;
			else if ((n >> 1) & 1 and n != 3)
				n++;
			else
				n--;
		}
		return ans;
	}
};