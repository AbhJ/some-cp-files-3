class Solution {
public:
	int maxProduct (vector<string>& words) {
		int n = words.size(), ans = 0;
		vector <int> v (n);
		for (int i = 0; i < n; i++) {
			for (auto c : words[i])
				v [i] |= (1 << (c - 'a'));
			for (int j = 0; j < i; j++)
				ans = max ((int) ((v[i] & v[j]) == 0) * (int) words[i].size() *
				           (int) words[j].size(), ans);
		}
		return ans;
	}
};