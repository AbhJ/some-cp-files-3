int Solution::firstMissingPositive (vector<int> &A) {
	int isone = 0, n = A.size();
	isone = count (A.begin(), A.end(), 1);
	if (isone == 0)
		return 1;
	for (int i = 0; i < n; i++) {
		if (A[i] < 1 or A[i] > n)
			A[i] = 1;
	}
	for (int i = 0; i < n; i++)
		A[abs (A[i]) - 1] = - abs (A[abs (A[i]) - 1]);
	for (int i = 0; i < n; i++) {
		if (A[i] > 0)
			return i + 1;
	}
	return n + 1;
}

