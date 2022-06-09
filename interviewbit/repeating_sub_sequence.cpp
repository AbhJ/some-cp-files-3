int Solution::anytwo (string A) {
	int n = A.length();
	vector<int>q[500];
	for (int i = 0; i < A.length(); i++)
		q[A[i]].emplace_back (i);
	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; j++)
			if (q[i].size() > 1 and q[j].size() > 1) {
				int a1 = q[i][0], a2 = q[i][1], b1 = q[j][q[j].size() - 1], b2 = q[j][q[j].size() - 2];
				if (a1 < b2 and a2 < b1)
					return 1;
			}
	return 0;
}
