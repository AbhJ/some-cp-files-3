class Solution {
public:
	int ans;

	void cnt(string s, int z) {
		int n = s.length(), cnt = 0, o = 0, e = 0;
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '(')
				cnt++, o++;
			if(s[i] == ')')
				cnt--, e++;
			if(cnt < 0 and z == 0)
				cnt = o = e = 0;
			if(cnt > 0 and z == 1)
				cnt = o = e = 0;
			if(cnt == 0)
				ans = max(ans, o << 1);
		}
	}

	int longestValidParentheses(string s) {
		ans = 0;
		cnt(s, 0);
		reverse(s.begin(), s.end());
		cnt(s, 1);
		return ans;
	}
};

