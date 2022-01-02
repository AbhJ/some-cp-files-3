class Solution {
public:
	bool asteroidsDestroyed (int mass, vector<int> &asteroids) {
		sort (asteroids.begin(), asteroids.end());
		long long massDup = mass;
		for (int i : asteroids) {
			if (i > massDup)
				return false;
			massDup += i;
		}
		return true;
	}
};
