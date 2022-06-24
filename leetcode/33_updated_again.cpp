class Solution {
public:
	int search (const vector<int> &A, int B) {
		int n = A.size(), l = 0, r = n - 1, m;
		while (l < r) {
			m = (l + r) / 2;
			if (A[m] > A[r])
				l = m + 1;
			else
				r = m;
		}
		//smallest number is at r
		if (binary_search (A.begin(), A.begin() + r, B))
			return lower_bound (A.begin(), A.begin() + r, B) - A.begin();
		if (binary_search (A.begin() + r, A.end(), B))
			return lower_bound (A.begin() + r, A.end(), B) - A.begin();
		return - 1;
	}
};
