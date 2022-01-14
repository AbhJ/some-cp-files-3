void Solution::arrange (vector<int> &A) {
	int n = A.size();
	for (int i = 0; i < n; i++) {
		A[i] = A[i] + n * (A[A[i]] % n);
		// conserve old value % n and bring new value / n
	}
	for (int i = 0; i < n; i++)
		A[i] /= n;
}

