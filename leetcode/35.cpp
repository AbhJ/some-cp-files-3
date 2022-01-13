class Solution {
public:
	int searchInsert (vector<int> &A, int B) {
		int n = A.size(), l = 0, r = n - 1;
		if (A[n - 1] < B)
			return n;
		while (l < r) {
			int m = l + r >> 1;
			if (A[m] >= B)
				r = m;
			else
				l = m + 1;
		}
		return r;
	}
};
