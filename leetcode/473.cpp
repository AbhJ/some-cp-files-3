class Solution {
public:

	map <vector<int>, bool> m;
	int tar;

	bool comp (vector<int> &sums) {
		sort (sums.begin(), sums.end());
		return sums[0] == sums[3];
	}

	bool f (vector<int> &sums, vector<int>& matchsticks, int ind) {
		int n = matchsticks.size();
		if (m.count (sums))
			return m[sums];
		if (ind == n) {
			if (comp (sums))
				return true;
			return m[sums] = false;
		}
		for (int places = 0; places < 4; places++)
			if (sums[places] + matchsticks[ind] <= tar) {
				sums[places] += matchsticks[ind];
				if (f (sums, matchsticks, ind + 1))
					return true;
				sums[places] -= matchsticks[ind];
			}
		return m[sums] = false;
	}

	bool makesquare (vector<int>& matchsticks) {
		sort (matchsticks.rbegin(), matchsticks.rend());
		vector<int> sums (4);
		tar = accumulate (matchsticks.begin(), matchsticks.end(), 0) / 4;
		m.clear();
		return f (sums, matchsticks, 0);
	}
};