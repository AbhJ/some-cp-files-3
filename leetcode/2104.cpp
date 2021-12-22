class Solution {
public:
	long long subArrayRanges (vector<int> &a) {
		int n = a.size();
		long long ans = 0;
		vector<long long>lg (n, - 1), rg (n, n), ll (n, - 1), rl (n, n);
		stack<int>s;
		for (int i = n - 1; i > -1; i--) {
			while (s.empty() == 0 and a[s.top()] < a[i])
				s.pop();
			if (s.empty() == 0)
				rg[i] = s.top();
			s.push (i);
		}
		s = stack<int>();
		for (int i = 0; i < n; i++) {
			while (s.empty() == 0 and a[s.top()] <= a[i])
				s.pop();
			if (s.empty() == 0)
				lg[i] = s.top();
			s.push (i);
		}
		s = stack<int>();
		for (int i = n - 1; i > -1; i--) {
			while (s.empty() == 0 and a[s.top()] > a[i])
				s.pop();
			if (s.empty() == 0)
				rl[i] = s.top();
			s.push (i);
		}
		s = stack<int>();
		for (int i = 0; i < n; i++) {
			while (s.empty() == 0 and a[s.top()] >= a[i])
				s.pop();
			if (s.empty() == 0)
				ll[i] = s.top();
			s.push (i);
		}
		for (int i = 0; i < n; i++)
			ans -= a[i] * ((i - ll[i]) * (rl[i] - i) - (i - lg[i]) * (rg[i] - i));
		return ans;
	}
};

