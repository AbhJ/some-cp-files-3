class Solution {
public:
	int nthUglyNumber (int n) {
		int mul2 = 2, mul3 = 3, mul5 = 5, ind2 = 0, ind3 = 0, ind5 = 0;
		vector <long long> a (n + 1, 1);
		for (int i = 1; i <= n; i++) {
			a[i] = min ({mul2, mul3, mul5});
			if (a[i] == mul2) {
				mul2 = a[++ind2] * 2;
			}
			if (a[i] == mul3) {
				mul3 = a[++ind3] * 3;
			}
			if (a[i] == mul5) {
				mul5 = a[++ind5] * 5;
			}
		}
		return (int) a[n - 1];
	}
};