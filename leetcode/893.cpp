class Solution {
public:
	int numSpecialEquivGroups (vector<string>& words) {
		set<pair<string, string>> s;
		for (string w : words) {
			string ev, od;
			for (int i = 0; i < w.size(); i += 2) {
				ev += w[i];
			}
			for (int i = 1; i < w.size(); i += 2) {
				od += w[i];
			}
			sort (ev.begin(), ev.end());
			sort (od.begin(), od.end());
			s.emplace (make_pair (ev, od));
		}
		return s.size();
	}
};