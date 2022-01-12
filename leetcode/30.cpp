class Solution {
public:
	vector<int> findSubstring (string A, vector<string> &B) {
		if (B.empty())
			return vector<int> (0);
		multiset<string>S;
		int k = B[0].length();
		for (auto &i : B)
			S.insert (i);
		vector<int>ok;
		for (int i = 0; i != A.length(); i++) {
			multiset<string>s;
			for (int j = i; j != i + B.size()*k; j += k) {
				if (j + k > A.length())
					break;
				s.insert (A.substr (j, k));
			}
			if (s == S)
				ok.push_back (i);
		}
		return ok;
	}
};
