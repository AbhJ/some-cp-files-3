vector<int> Solution::findPerm (const string A, int B) {
	int n = B, len = A.size();
	vector<int>a, s;
	for (int i = 0; i < len; i++) {
		s.push_back (i + 1);
		if (A[i] == 'I') {
			while (!s.empty())
				a.push_back (s.back()), s.pop_back();
		}
	}
	s.push_back (len + 1);
	while (!s.empty())
		a.push_back (s.back()), s.pop_back();
	return a;
}

