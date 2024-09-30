int Solution::solve (vector<int> &A, int B) {
	int Solution::solve (vector<vector<int> > &A) {
		map <int, int> m;
		for (int i = 0; i < A.size(); i++) {
			m[A[i][0]]++;
			m[A[i][1]]--;
		}
		int cnt = 0, ans = 0;
		for (auto i : m) {
			cnt += i.second;
			ans = max (cnt, ans);
		}
		return ans;
	}
}