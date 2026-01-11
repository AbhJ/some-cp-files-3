class Solution {
public:
	int earliestFullBloom (vector<int>& plantTime, vector<int>& growTime) {
		// higher growth time should be planted earlier
		vector <pair<int, int>> v;
		int n = plantTime.size();
		for (int i = 0; i < growTime.size(); i++) {
			v.emplace_back (growTime[i], - plantTime[i]);
		}
		sort (v.rbegin(), v.rend());
		int daysPlanting = 0, earliestAns = 0;
		for (int i = 0; i < n; i++) {
			auto [grow, negPlan] = v[i];
			int plan = - negPlan;
			daysPlanting += plan;
			earliestAns = max (daysPlanting + grow, earliestAns);
		}
		return earliestAns;
	}
};