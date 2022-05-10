int Solution::findMedian (vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	int pos = (n * m + 1) / 2;
	int l = 1, r = 1e9;
	while (l < r) {
		int mid = l + r >> 1, x = 0;
		for (int i = 0; i < n; i++) {
			int p = upper_bound (A[i].begin(), A[i].end(), mid) - A[i].begin();
			x += p;
		}
		if (x >= pos)
			r = mid;
		else
			l = mid + 1;
	}
	return r;
}
