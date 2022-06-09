vector<int> Solution::wave (vector<int> &A) {
	sort (A.begin(), A.end());
	for (int i = 0; 2 * i + 1 < A.size(); i++)
		swap (A[2 * i], A[2 * i + 1]);
	return A;
}

