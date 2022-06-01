class Solution {
public:
	int maximumBags (vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
		vector<pair<int, int>> v (capacity.size());
		for (int i = 0; i < capacity.size(); i++) {
			v[i] = {capacity[i] - rocks[i], rocks[i]};
		}
		sort (v.begin(), v.end());
		int cnt = 0;
		for (auto &[x, y] : v) {
			if (additionalRocks < x)
				break;
			cnt ++;
			additionalRocks -= x;
		}
		return cnt;
	}
};
