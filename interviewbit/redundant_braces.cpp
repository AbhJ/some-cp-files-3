int Solution::braces (string A) {
	stack<char>s;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != ')') {
			s.push (A[i]);
			continue;
		}
		int cnt = 0;
		while (s.top() != '(')
			cnt++, s.pop();
		s.pop();
		if (cnt <= 1)
			return 1;
	}
	return 0;
}
