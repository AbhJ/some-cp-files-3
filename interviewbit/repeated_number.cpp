int Solution::repeatedNumber (const vector<int> &A) {
	int f = 0, s = 0, F = - 1, S = - 1;
	for (auto i : A) {
		if (i == F)
			f++;
		else if (i == S)
			s++;
		else if (f == 0) {
			F = i;
			f = 1;
		}
		else if (s == 0) {
			S = i;
			s = 1;
		}
		else {
			f--;
			s--;
		}
	}
	f = s = 0;
	for (auto i : A) {
		if (i == F)
			f++;
		if (i == S)
			s++;
	}
	if (f < s and s > A.size() / 3)
		return S;
	if (f >= s and f > A.size() / 3)
		return F;
	return - 1;
}
