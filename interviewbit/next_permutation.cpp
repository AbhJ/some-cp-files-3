vector<int> Solution::nextPermutation (vector<int> &A) {
	int i, j;
	int n = A.size();
	for (i = n - 2; i >= 0; i --) {
		if (A[i] < A[i + 1])
			break;
	}
	if (i == -1) {
		reverse (A.begin(), A.end());
		return A;
	}
	for (j = n - 1; j > i; j --) {
		if (A[j] > A[i])
			break;
	}
	swap (A[j], A[i]);
	// both produce the same result
	// sort (A.begin() + i + 1, A.end());
	reverse (A.begin() + i + 1, A.end());
	return A;
}

