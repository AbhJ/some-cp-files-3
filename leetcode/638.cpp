class Solution {
public:
	map <vector<int>, int> dp;
	int shoppingOffers (vector<int>& price, vector<vector<int>>& special,
	                    vector<int>& needs) {
		if (dp.count (needs))
			return dp[needs];
		int n = needs.size();
		int ans = 0;
		assert (price.size() == n);
		for (int i = 0; i < n; i++) {
			ans += (price[i] * needs[i]);
		}
		for (auto v : special) {
			bool isPossible = true;
			for (int i = 0; i < n; i++) {
				if (v[i] > needs[i])
					isPossible = false;
			}
			auto newNeed = needs;
			if (isPossible) {
				for (int i = 0; i < n; i++)
					newNeed[i] -= v[i];
				ans = min (ans, v[n] + shoppingOffers (price, special, newNeed));
			}
		}
		return dp [needs] = ans;
	}
};