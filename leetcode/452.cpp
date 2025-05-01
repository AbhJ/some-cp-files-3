class Solution {
public:
	static bool cmp (vector<int>& a, vector<int>& b) {
		return a[1] < b[1];
	}
	int findMinArrowShots (vector<vector<int>>& points) {
		sort (points.begin(), points.end(), cmp);
		int cnt = 0;
		for (int i = 0; i < points.size();) {
			int en = points[i][1], j = i;
			for (; j < points.size() and points[j][0] <= en; j++);
			cnt++;
			i = j;
		}
		return cnt;
	}
};