class Solution {
public:
	int minSteps (string s, string t) {
		map<char, int>S, T;
		int ans = 0;
		for (auto c : s)
			S[c]++;
		for (auto c : t)
			T[c]++;
		for (auto [c, cnt] : S)
			ans += max (0, cnt - T[c]);
		for (auto [c, cnt] : T)
			ans += max (0, cnt - S[c]);
		return ans;
	}
};
