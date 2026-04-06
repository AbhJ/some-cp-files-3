class Solution {
public:
	vector<int> countRectangles (vector<vector<int>>& rectangles,
	                             vector<vector<int>>& points) {
		int n = points.size(), m = rectangles.size();
		vector <int> rectX[101], ans (n);
		for (int i = 0; i < m; i++)
			rectX[rectangles[i][1]].emplace_back (rectangles[i][0]);
		for (int i = 0; i <= 100; i++)
			sort (rectX[i].begin(), rectX[i].end());
		for (int i = 0; i < n; i++) {
			int x = points[i][0], h = points[i][1];
			for (int j = h; j <= 100; j++)  {
				// for every height count rectangles
				auto posi = lower_bound (rectX[j].begin(), rectX[j].end(), x);
				ans[i] += rectX[j].end() - posi;
			}
		}
		return ans;
	}
};