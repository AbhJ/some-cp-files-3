class Solution {
public:
	int change (int amount, vector<int>& coins) {
		vector <long long> dp (amount + 1);
		dp[0] = 1;
		int n = coins.size();
		for (auto cur : coins) {
			for (int i = 0; i <= amount; i++) if (i + cur <= amount
				                                      and dp[i + cur] < (1LL << 32)) {
					dp [i + cur] += dp [i];
				}
		}
		return dp.back();
	}
};