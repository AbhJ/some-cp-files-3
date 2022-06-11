class Solution {
public:
	int longestValidParentheses (string s) {
		int n = s.length(), cnt = 0, in = 0, ans = 0;
		stack<int> S;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				S.emplace (i);
			else if (S.empty() == 1 or s[S.top()] == ')')
				S.emplace (i);
			else
				S.pop();
		}
		int last = n;
		while (S.empty() == 0) {
			ans = max (ans, last - S.top() - 1);
			last = S.top();
			S.pop();
		}
		ans = max (ans, last);
		return ans;
	}
};
