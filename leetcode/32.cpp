class Solution {
public:
	int longestValidParentheses (string s) {
		int l = s.length();
		stack <int> S;
		vector<int> lengths;
		for (int i = 0; i < l; i++) {
			if (s[i] == '(')
				S.push (i);
			else {
				if (S.empty() == 0 and s[S.top()] == '(')
					S.pop();
				else
					S.push (i);
				// WE ONLY HAVE UNSOLVED PARANTHESIS IN STACK
			}
		}
		int fin = l;
		while (S.empty() == 0) {
			int sta = S.top();
			S.pop();
			lengths.emplace_back (fin - sta - 1);
			fin = sta;
		}
		int sta = - 1;
		lengths.emplace_back (fin - sta - 1);
		return *max_element (lengths.begin(), lengths.end());
	}
};
