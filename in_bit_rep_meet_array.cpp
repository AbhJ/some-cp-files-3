#define pb push_back
vector<int> Solution::repeatedNumber (const vector<int> &B) {
	vector<int> A = B;
	int n = B.size();
	int doub, miss;
	for (int i = 0; i < n; i++) {
		if (A[abs (A[i]) - 1] < 0)
			doub = abs (A[i]);
		else
			A[abs (A[i]) - 1] *= -1;
	}
	for (int i = 0; i < n; i++)
		if (A[i] >= 0)
			miss = i + 1;
	return vector<int> {doub, miss};
}
