int Solution::solve (vector<int> &A) {
	sort (A.begin(), A.end());
	for (int i = 0; i < A.size(); i++) {
		if (i != A.size() - 1 and A[i + 1] == A[i])
			continue;
		int greater = A.size() - (i + 1);
		if (greater == A[i])
			return 1;
	}
	return -1;
}
