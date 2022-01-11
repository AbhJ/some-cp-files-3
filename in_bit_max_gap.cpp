int Solution::maximumGap (const vector<int> &A) {
	vector<int>P (A.size() + 1, 0);
	vector<pair<int, int>>m;
	for (int i = A.size() - 1; i > -1; i--) {
		m.push_back ({A[i], i});
	}
	sort (m.begin(), m.end());
	int mi = 1e9, ans = - 1;
	for (int i = 0; i < A.size(); i++) {
		mi = min (mi, m[i].second);
		ans = max (ans, m[i].second - mi);
	}
	return ans;
}
