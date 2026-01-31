class Solution {
public:
	int maximizeSquareArea (int m, int n, vector<int>& hFences,
	                        vector<int>& vFences) {
		hFences.emplace_back (1);
		hFences.emplace_back (m);
		vFences.emplace_back (1);
		vFences.emplace_back (n);
		sort (hFences.begin(), hFences.end());
		sort (vFences.begin(), vFences.end());
		unordered_set <int> s;
		for (int i = 0; i < hFences.size(); i++) {
			for (int j = i + 1; j < hFences.size(); j++) {
				s.emplace (hFences[j] - hFences[i]);
			}
		}
		int ans = - 1;
		for (int i = 0; i < vFences.size(); i++) {
			for (int j = i + 1; j < vFences.size(); j++) {
				if (s.count (vFences[j] - vFences[i])) {
					ans = max (vFences[j] - vFences[i], ans);
				}
			}
		}
		if (ans == - 1)
			return - 1;
		return ((long long) ans * (long long) ans) % ((long long) 1e9 + 7);
	}
};