class Solution {
public:
	int largestRectangleArea (vector<int> &heights) {
		stack<int>s;
		int n = heights.size(), ans = 0;
		vector<int> l (n, - 1), r (n, n);
		for (int i = 0; i < n; i++) {
			while (s.empty() == 0 and heights[s.top()] >= heights[i])
				s.pop();
			if (s.empty() == 0)
				l[i] = s.top();
			s.emplace (i);
		}
		s = stack<int>();
		for (int i = n - 1; i > - 1; i--) {
			while (s.empty() == 0 and heights[s.top()] >= heights[i])
				s.pop();
			if (s.empty() == 0)
				r[i] = s.top();
			s.emplace (i);
		}
		for (int i = 0; i < n; i++)
			ans = max (ans, (r[i] - l[i] - 1) * heights[i]);
		return ans;
	}
};
