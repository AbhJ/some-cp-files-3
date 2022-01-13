class Solution {
public:
	int mySqrt (int A) {
		long long B = A, l = 0, r = B, m;
		while (l < r) {
			m = l + r + 1 >> 1;
			if (m * m > B)
				r = m - 1;
			else
				l = m;
		}
		return l;
	}
};
