class Solution {
public:
	static bool cmp (vector <int> a, vector <int> b) {
		return a[1] < b[1];
	}
	int findLongestChain (vector<vector<int>>& pairs) {
		sort (pairs.begin(), pairs.end(), cmp);
		int e = - 1001, cnt = 0;
		for (int i = 0; i < pairs.size(); i++) {
			if (pairs[i][0] > e)
				e = pairs[i][1], cnt++;
		}
		return cnt;
	}
};