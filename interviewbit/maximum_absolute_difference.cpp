int Solution::maxArr (vector<int> &A) {
	int n = A.size(), mindif = 1e9, maxdif = -1e9, minadd = 1e9, maxadd = -1e9;
	for (int i = 0; i < n; i++) {
		mindif = min (mindif, A[i] - i);
		minadd = min (minadd, A[i] + i);
		maxdif = max (maxdif, A[i] - i);
		maxadd = max (maxadd, A[i] + i);
	}
	// assuming a[i] >= a[j]
	// a[i] - a[j] + i - j
	// (a[i] + i) - (a[j] + j)
	// a[i] - a[j] - i + j
	// (a[i] - i) - (a[j] - j)
	//dry run for [1, 3, - 1]
	//mina mind maxa maxd
	//1    1    1    1
	//1    1    4    2
	//1    -3   4    2
	return max (maxadd - minadd, maxdif - mindif);
}
