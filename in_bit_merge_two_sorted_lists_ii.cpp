void Solution::merge (vector<int> &A, vector<int> &B) {
	vector<int>C;
	int j = 0, i = 0;
	while (i < A.size() and j < B.size()) {
		if (A[i] < B[j])
			C.push_back (A[i++]);
		else
			C.push_back (B[j++]);
	}
	while (i != A.size())
		C.emplace_back (A[i++]);
	while (j != B.size())
		C.emplace_back (B[j++]);
	A = C;
}
