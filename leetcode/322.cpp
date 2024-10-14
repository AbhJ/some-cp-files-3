class Solution {
public:
	int coinChange (vector<int>& coins, int amount) {
		vector<int> minCoins (amount + 1, 1e9);
		minCoins[0] = 0;
		int n = coins.size();
		for (int am = 1; am <= amount; am++) {
			for (int i = 0; i < n; i++) if (am - coins[i] >= 0) {
					minCoins[am] = min (1 + minCoins[am - coins[i]], minCoins[am]);
				}
		}
		return minCoins[amount] == 1e9 ? - 1 : minCoins[amount];
	}
};