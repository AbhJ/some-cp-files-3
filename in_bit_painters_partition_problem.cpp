int Solution::paint (int A, int B, vector<int> &v) {
	if (v.empty())
		return 0;
	int n = v.size();
	long long int l = 0, r = 1e18;
	while (l < r) {
		long long int m = l + r >> 1, F = 0, cntPainters = 1, curTime = 0;
		for (int i = 0; i < n; i++) {
			if (1LL * v[i] * B > m) {
				F = 1;
				break;
			}
			if (curTime + 1LL * v[i] * B > m)
				cntPainters++, curTime = 1LL * v[i] * B;
			else
				curTime += 1LL * v[i] * B;
		}
		if (cntPainters <= A and F == 0)
			r = m;
		else
			l = m + 1;
	}
	return r % 10000003;
}
