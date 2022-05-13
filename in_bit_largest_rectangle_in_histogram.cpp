int Solution::largestRectangleArea (vector<int> &A) {
	stack<int>s;
	int n = A.size();
	long long ans = 0;
	vector<long long>l (n, - 1LL), r (n, n);
	for (int i = 0; i < n; i++) {
		while (s.empty() == 0 and A[s.top()] >= A[i])
			s.pop();
		if (s.empty() == 0)
			l[i] = s.top();
		s.push (i);
	}
	s = stack<int>();
	for (int i = n - 1; ~i; i--) {
		while (s.empty() == 0 and A[s.top()] >= A[i])
			s.pop();
		if (s.empty() == 0)
			r[i] = s.top();
		s.push (i);
	}
	for (int i = 0; i < n; i++)
		ans = max (ans, A[i] * ((r[i] - 1) - (l[i] + 1) + 1));
	return ans;
}
