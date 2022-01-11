class Solution {
public:
	int largestRectangleArea (vector<int> &a) {
		int n = a.size();
		vector<int> l (n, - 1), r (n, n);
		stack<int>s;
		for (int i = 0; i < n; i++) {
			while (s.empty() == 0 and a[s.top()] >= a[i])
				s.pop();
			if (s.empty() == 0)
				l[i] = s.top();
			s.push (i);
		}
		s = stack<int>();
		for (int i = n - 1; i > - 1; i--) {
			while (s.empty() == 0 and a[s.top()] >= a[i])
				s.pop();
			if (s.empty() == 0)
				r[i] = s.top();
			s.push (i);
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max (ans, ((r[i] - l[i] - 1) * a[i]));
		return ans;
	}
};
