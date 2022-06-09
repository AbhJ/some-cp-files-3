bool cmp (string s, string t) {
	return s + t > t + s;
}
string Solution::largestNumber (const vector<int> &A) {
	vector<string>s;
	string S;
	for (auto i : A)
		s.push_back (to_string (i));
	sort (s.begin(), s.end(), cmp);
	for (auto i : s)
		S += i;
	if (S.empty() == 0 and S.front() == '0')
		return "0";
	return S;
}
