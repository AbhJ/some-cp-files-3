class Solution {
public:
	static bool cmp (vector<int> &a, vector<int> &b) {
		return a[1] < b[1];
	}
	int eraseOverlapIntervals (vector<vector<int>>& intervals) {
		sort (intervals.begin(), intervals.end(), cmp);
		int lastEnd = - 5e4, cnt = 0;
		for (auto x : intervals) {
			if (x[0] < lastEnd) {
				cnt++;
				continue;
			}
			lastEnd = max (x[1], lastEnd);
		}
		return cnt;
	}
};