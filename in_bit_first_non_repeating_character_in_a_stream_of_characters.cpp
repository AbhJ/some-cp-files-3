string Solution::solve (string A) {
	queue<char>q;
	vector<int>c (26, 0);
	string s;
	for (auto &i : A) {
		q.push (i);
		c[i - 'a']++;
		while (q.empty() == 0 and c[q.front() - 'a'] > 1)
			q.pop();
		if (q.empty() == 1)
			s += '#';
		else
			s += q.front();
	}
	return s;
}
