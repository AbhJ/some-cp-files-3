vector<int> Solution::searchRange (const vector<int> &A, int B) {
	int n = A.size(), l = 0, r = n - 1, m, L = - 1, R = - 1;
	while (l < r) {
		m = (l + r + 1) / 2;
		if (A[m] <= B)
			l = m;
		else
			r = m - 1;
	}
	if (A[l] == B)
		R = l;
	l = 0, n - 1;
	while (l < r) {
		m = (l + r) / 2;
		if (A[m] >= B)
			r = m;
		else
			l = m + 1;
	}
	if (A[r] == B)
		L = r;
	return (~L and ~R ? vector<int> {L, R} : vector<int> {- 1, - 1});
}

