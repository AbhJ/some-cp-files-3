int Solution::repeatedNumber (const vector<int> &A) {
	vector <int> B = A;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		if (B[abs (B[i]) - 1] < 0)
			return abs (B[i]);
		else
			B[abs (B[i]) - 1] = - B[abs (B[i]) - 1];
	}
	return - 1;
}
